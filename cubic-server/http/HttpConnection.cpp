#include "HttpConnection.hpp"
#include <boost/asio/ip/tcp.hpp>

using tcp = boost::asio::ip::tcp;
namespace beast = boost::beast; // from <boost/beast.hpp>
namespace bhttp = beast::http; // from <boost/beast/http.hpp>
using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>

namespace http {

HttpConnection::HttpConnection(tcp::socket socket):
    _socket(std::move(socket))
{
}

void HttpConnection::start()
{
    _readRequest();
    _checkDeadline();
}

void HttpConnection::_readRequest()
{
    auto self = shared_from_this();

    bhttp::async_read(_socket, _buffer, _request, [self](beast::error_code ec, std::size_t bytes_transferred) {
        boost::ignore_unused(bytes_transferred);
        if (!ec)
            self->_processRequest();
    });
}

void HttpConnection::_processRequest()
{
    _response.version(_request.version());
    _response.keep_alive(false);

    switch (_request.method()) {
    case bhttp::verb::get:
        _response.result(bhttp::status::ok);
        _createResponse();
        break;

    default:
        // We return responses indicating an error if
        // we do not recognize the request method.
        _response.result(bhttp::status::bad_request);
        _response.set(bhttp::field::content_type, "text/plain");
        beast::ostream(_response.body()) << "Invalid request-method '" << std::string(_request.method_string()) << "'";
        break;
    }

    _writeResponse();
}

void HttpConnection::_createResponse()
{
    if (_request.target() == "/metrics") {
        _response.set(bhttp::field::content_type, "text/html");
        beast::ostream(_response.body()) << "<html>\n"
                                         << "<head><title>Some title</title></head>\n"
                                         << "<body>\n"
                                         << "<h1>Request count</h1>\n"
                                         << "<p>There have been " << 1 << " requests so far.</p>\n"
                                         << "</body>\n"
                                         << "</html>\n";
    } else {
        _response.result(bhttp::status::not_found);
        _response.set(bhttp::field::content_type, "text/plain");
        beast::ostream(_response.body()) << "File not found\r\n";
    }
}

void HttpConnection::_writeResponse()
{
    auto self = shared_from_this();

    _response.content_length(_response.body().size());

    bhttp::async_write(_socket, _response, [self](beast::error_code ec, std::size_t) {
        self->_socket.shutdown(tcp::socket::shutdown_send, ec);
        self->_deadline.cancel();
    });
}

void HttpConnection::_checkDeadline()
{
    auto self = shared_from_this();

    _deadline.async_wait([self](beast::error_code ec) {
        if (!ec) {
            // Close socket to cancel any outstanding operation.
            self->_socket.close(ec);
        }
    });
}

}
