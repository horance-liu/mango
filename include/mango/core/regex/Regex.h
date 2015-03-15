#ifndef HF796254F_9C83_4BF9_A953_9DFEB404F57E
#define HF796254F_9C83_4BF9_A953_9DFEB404F57E

#include "mango/core/regex/RegexMatch.h"

MANGO_NS_BEGIN

struct RegexImpl;

struct Regex
{
    Regex(const std::string& pattern);
    ~Regex();

    bool find(const std::string& desc, RegexMatch& match) const;
    bool findAll(const std::string& desc, RegexMatch& match) const;

    std::string str() const;

private:
    RegexImpl* impl;
};

MANGO_NS_END
#endif
