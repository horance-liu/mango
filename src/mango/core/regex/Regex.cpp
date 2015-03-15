#include <mango/core/regex/Regex.h>
#include "mango/core/regex/RegexMatch.h"
#include <boost/regex.hpp>

MANGO_NS_BEGIN

struct RegexImpl
{
    RegexImpl(const std::string& pattern)
      : regex(pattern.c_str())
    {
    }

    bool find(const std::string& str, RegexMatch& match) const
    {

        boost::cmatch results;
        if (!boost::regex_search(str.c_str(), results, regex, boost::regex_constants::match_extra))
        {
            return false;
        }

        for (auto i = 1lu; i < results.size(); ++i)
        {
            match.emplace_back(results.str(i), results.position(i));
        }

        return true;
    }

    bool findAll(const std::string& str, RegexMatch& match) const
    {
        boost::sregex_token_iterator first(str.begin(), str.end(), regex, 1
            , boost::regex_constants::match_continuous);
        boost::sregex_token_iterator last;

        for (; first != last; ++first)
        {
            match.emplace_back(*first);
        }

        return !match.empty();
    }

    std::string str() const
    {
        return regex.str();
    }

private:
    boost::regex regex;
};

Regex::Regex(const std::string& pattern)
  : impl(new RegexImpl(pattern))
{}

Regex::~Regex()
{
    delete impl;
}

bool Regex::find(const std::string& str, RegexMatch& match) const
{
    return impl->find(str, match);
}

bool Regex::findAll(const std::string& str, RegexMatch& match) const
{
    return impl->findAll(str, match);
}

std::string Regex::str() const
{
    return impl->str();
}

MANGO_NS_END
