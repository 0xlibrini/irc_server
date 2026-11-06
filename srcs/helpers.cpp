#include "../includes/Server.hpp"



bool Server::isValidNick(const std::string &nick)
{
    size_t i;

    if (nick.empty())
        return (false);

    i = 0;
    while (i < nick.length())
    {
        if (!std::isalnum(nick[i])
            && nick[i] != '_'
            && nick[i] != '-')
            return (false);
        ++i;
    }
    return (true);
}

bool Server::isValidChannelName(const std::string &name)
{
    if (name.empty())
        return (false);
    if (name[0] != '#')
        return (false);
    if (name.length() > 2)
        return (true);
    return (false);
}

bool Server::nickExists(const std::string &nick)
{
    std::map<int, Client *>::iterator it;

    it = _clients.begin();
    while (it != _clients.end())
    {
        if (it->second->getNick() == nick)
            return (true);
        ++it;
    }
    return (false);
}


void Server::sendReply(int fd, const std::string &msg)
{
    send(fd, msg.c_str(), msg.size(), 0);
}

void Server::sendToChannel(Channel *channel,const std::string &msg,int excludeFd)
{
    std::map<int, Client *>::const_iterator it;

    it = channel->getMembers().begin();

    while (it != channel->getMembers().end())
    {
        if (it->first != excludeFd)
            sendReply(it->first, msg);
        ++it;
    }
}

void Server::sendToChannel(Channel *channel,const std::string &msg)
{
    std::map<int, Client *>::const_iterator it;

    it = channel->getMembers().begin();

    while (it != channel->getMembers().end())
    {
        sendReply(it->first, msg);
        ++it;
    }
}


bool Server::isAllowedBeforeRegister(const std::string &cmd)
{
    return (
        cmd == "CAP" || cmd == "cap" ||
        cmd == "PASS" || cmd == "pass" ||
        cmd == "NICK" || cmd == "nick" ||
        cmd == "USER" || cmd == "user" ||
        cmd == "QUIT" || cmd == "quit" ||
        cmd == "PING" || cmd == "ping"
    );
}
