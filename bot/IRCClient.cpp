#include "IRCClient.hpp"
IRCClient::IRCClient()
{
    _socket = -1;
}

IRCClient::~IRCClient()
{
    if (_socket != -1)
        close(_socket);
}

bool IRCClient::connectToServer(const std::string &host, int port)
{
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket < 0)
        return false;
    sockaddr_in server;
    std::memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &server.sin_addr);
    if (connect(_socket,(sockaddr *)&server, sizeof(server)) < 0)
        return false;
    return true;
}

void IRCClient::sendRaw(const std::string &msg)
{
    send(_socket,msg.c_str(),msg.size(), 0);
}

void IRCClient::login(const std::string &password, const std::string &nick, const std::string &user)
{
    sendRaw("PASS " + password + "\r\n");
    sendRaw("NICK " + nick + "\r\n");
    sendRaw("USER " + user + " 0 * :" + user + "\r\n");
}

void IRCClient::joinChannel(const std::string &channel)
{
    sendRaw("JOIN "+ channel + "\r\n");
}

std::string IRCClient::receive()
{
    char buffer[512];
    int n = recv(_socket,buffer,sizeof(buffer)-1, 0);
    if (n <= 0)
        return "";
    buffer[n] = '\0';
    return std::string(buffer);
}

int IRCClient::getSocket() const
{
    return _socket;
}