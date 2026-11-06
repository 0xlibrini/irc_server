#include "bot.hpp"

Bot::Bot()
{
    _badWords.push_back("idiot");
    _badWords.push_back("stupid");
    _badWords.push_back("spam");
}

bool Bot::containsBadWord(const std::string &message)
{
    for (size_t i = 0; i < _badWords.size(); i++)
    {
        if (message.find(_badWords[i]) != std::string::npos)
            return true;
    }
    return false;
}