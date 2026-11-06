#include <iostream>
#include <string>
#include <sstream>
#include "IRCClient.hpp"
#include "bot.hpp"
#include <cstring>
#include <cstdlib>
#include <signal.h>



int main(int argc, char **argv)
{
    if (argc != 5)
    {
        std::cout << "Usage: " << argv[0] << " <channel> <port> <host> <password>" << std::endl;
        std::cout << "Example: " << argv[0] << " \"#general\" 6667 localhost mypassword" << std::endl;
        return 1;
    }
    IRCClient irc;
    Bot bot;
    if (strcmp(argv[3],"localhost") == 0)
        strcpy(argv[3],"127.0.0.1");
    if (!irc.connectToServer(argv[3], atoi(argv[2])))
    {
        std::cout << "Connection failed" << std::endl;
        return 1;
    }
    irc.login(argv[4], "BadWordBot", "bot");
    irc.joinChannel(argv[1]);
    irc.setupSignals();
    while (!IRCClient::F_signal)
    {
        std::string line = irc.receive();
        if (line.empty())
            break;
        std::cout << line;
        std::string nickname = irc.getNickname(line);
        // Get message
        size_t pos = line.find(" :");
        if (pos == std::string::npos)
            continue;
        std::string message = line.substr(pos + 2);
        if (bot.containsBadWord(message))
        {
            std::cout << "\n=========================\n";
            std::cout << "Bad word detected!" << std::endl;
            std::cout << "User    : " << nickname << std::endl;
            std::cout << "Channel : " << argv[1] << std::endl;
            std::cout << "Message : " << message << std::endl;
            std::cout << "=========================\n";

            irc.sendRaw("KICK " + std::string(argv[1]) + " " + nickname + " :Bad language\r\n");
        }
    }

    return 0;
}