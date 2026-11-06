#ifndef IRCCLIENT_HPP
#define IRCCLIENT_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
class IRCClient
{
    private:
    int _socket;
    public:
    IRCClient();
    static bool F_signal;
    ~IRCClient();
    bool connectToServer(const std::string &host, int port);
    void login(const std::string &password, const std::string &nick,const std::string &user);
    void joinChannel(const std::string &channel);
    void sendRaw(const std::string &msg);
    std::string receive();
    static void SignalHandler(int SignalNum);
    static void setupSignals();
    std::string getNickname(const std::string &line);
    int getSocket() const;
};

#endif