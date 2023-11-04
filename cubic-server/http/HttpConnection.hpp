#ifndef B4EBB362_DE83_491A_ABED_DAE947C26FAB
#define B4EBB362_DE83_491A_ABED_DAE947C26FAB

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <memory>

namespace http {

constexpr auto maxTimePerConnection = 30;

class HttpConnection : public std::enable_shared_from_this<HttpConnection> {
    using tcp = boost::asio::ip::tcp;

public:
    HttpConnection(tcp::socket socket);

    // Initiate the asynchronous operations associated with the connection.
    void start();

private:
    // The socket for the currently connected client.
    tcp::socket _socket;

    // The buffer for performing reads.
    boost::beast::flat_buffer _buffer {8192};

    // The request message.
    boost::beast::http::request<boost::beast::http::dynamic_body> _request;

    // The response message.
    boost::beast::http::response<boost::beast::http::dynamic_body> _response;

    // The timer for putting a deadline on connection processing.
    boost::asio::steady_timer _deadline {_socket.get_executor(), std::chrono::seconds(maxTimePerConnection)};

    // Asynchronously receive a complete request message.
    void _readRequest();

    // Determine what needs to be done with the request message.
    void _processRequest();

    // Construct a response message based on the program state.
    void _createResponse();

    // Asynchronously transmit the response message.
    void _writeResponse();

    // Check whether we have spent enough time on this connection.
    void _checkDeadline();
};

}

#endif /* B4EBB362_DE83_491A_ABED_DAE947C26FAB */
