#include "mango/core/wire/server/WireServer.h"
#include "mango/core/wire/server/WireHandler.h"
#include <boost/asio.hpp>

MANGO_NS_BEGIN

////////////////////////////////////////////////////////////////////////////////
using namespace boost::asio;
using namespace boost::asio::ip;

////////////////////////////////////////////////////////////////////////////////
struct WireServerImpl
{
    WireServerImpl() : acceptor(ios)
    {}

    void listen(unsigned short port)
    {
        tcp::endpoint endpoint(tcp::v4(), port);
        acceptor.open(endpoint.protocol());
        acceptor.set_option(tcp::acceptor::reuse_address(true));
        acceptor.bind(endpoint);
        acceptor.listen(1);
    }

    void accept(const WireHandler& handler)
    {
        tcp::iostream stream;
        acceptor.accept(*stream.rdbuf());
        processStream(stream, handler);
    }

private:
    void processStream(tcp::iostream &stream, const WireHandler& handler)
    {
        std::string request;
        while (getline(stream, request))
        {
            stream << handler.handle(request)
                   << std::endl << std::flush;
        }
    }

private:
    io_service ios;
    tcp::acceptor acceptor;
};

////////////////////////////////////////////////////////////////////////////////
WireServer::WireServer()
  : impl(new WireServerImpl)
{}

////////////////////////////////////////////////////////////////////////////////
WireServer::~WireServer()
{
    delete impl;
}

////////////////////////////////////////////////////////////////////////////////
void WireServer::listen(unsigned short port)
{
    impl->listen(port);
}

////////////////////////////////////////////////////////////////////////////////
void WireServer::accept()
{
    impl->accept(ROLE(WireHandler));
}

MANGO_NS_END
