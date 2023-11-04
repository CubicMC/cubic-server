#ifndef AC8CBA06_158A_4D75_B638_395F9E43B6FF
#define AC8CBA06_158A_4D75_B638_395F9E43B6FF

#include <boost/asio.hpp>

namespace http {

void relaunchHttpServer(boost::asio::ip::tcp::acceptor &acceptor, boost::asio::ip::tcp::socket &socket);

void launchHttpServer();

}

#endif /* AC8CBA06_158A_4D75_B638_395F9E43B6FF */
