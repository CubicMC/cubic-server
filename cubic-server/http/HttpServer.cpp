#include "HttpServer.hpp"
#include "HttpConnection.hpp"
#include "logging/logging.hpp"

namespace beast = boost::beast;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

namespace http {

void relaunchHttpServer(tcp::acceptor &acceptor, tcp::socket &socket)
{
    acceptor.async_accept(socket, [&](beast::error_code ec) {
        if (!ec)
            std::make_shared<HttpConnection>(std::move(socket))->start();
        relaunchHttpServer(acceptor, socket);
    });
}

void launchHttpServer()
{
    while (1) {
        try {
            const auto address = net::ip::make_address("0.0.0.0");
            const unsigned short port = 8080;

            net::io_context ioc {1};

            tcp::acceptor acceptor {ioc, {address, port}};
            tcp::socket socket {ioc};
            relaunchHttpServer(acceptor, socket);

            ioc.run();
        } catch (const std::exception &e) {
            LERROR("HttpServer error: {}", e.what());
        }
    }
}

}
