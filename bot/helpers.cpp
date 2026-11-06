#include "IRCClient.hpp"
#include <signal.h>


std::string IRCClient::getNickname(const std::string &line)
{
    size_t start = line.find(':');
    if (start == std::string::npos)
        return "";

    size_t end = line.find('!', start);
    if (end == std::string::npos)
        return "";

    return line.substr(start + 1, end - start - 1);
}
bool IRCClient::F_signal = false;
void IRCClient::SignalHandler(int SignalNum)
{
    (void)SignalNum;
    F_signal = true;
}

void IRCClient::setupSignals()
{
    struct sigaction sa;

    sa.sa_handler = IRCClient::SignalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
}