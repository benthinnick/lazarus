#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <iostream>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

int main() {
  try {
    net::io_context ioc;

    tcp::acceptor acceptor{ioc, {net::ip::make_address("127.0.0.1"), 8080}};
    tcp::socket socket{ioc};

    acceptor.accept(socket);

    beast::flat_buffer buffer;
    http::request<http::string_body> req;
    http::read(socket, buffer, req);

    http::response<http::string_body> res{http::status::ok, req.version()};
    res.set(http::field::server, "Boost.Beast/248");
    res.set(http::field::content_type, "text/plain");
    res.body() = "Hello, World!";
    res.prepare_payload();

    http::write(socket, res);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
