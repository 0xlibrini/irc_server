#ifndef BOT_HPP
#define BOT_HPP

#include <string>
#include <vector>

class Bot
{
    private:
    std::vector<std::string> _badWords;
    public:
    Bot();
    bool containsBadWord(const std::string &message);
};

#endif