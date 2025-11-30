#include <globalUtils.hpp>

bool endsWith(const std::string &str, const std::string &suffix)
{
    if (suffix.size() > str.size())
        return false;
    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool startsWith(const std::string &str, const std::string &prefix)
{
    if (prefix.size() > str.size())
        return false;
    return str.compare(0, prefix.size(), prefix) == 0;
}

void printArgs(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "Arg " << i << ": " << argv[i] << std::endl;
    }
}

void print()
{
    return;
}

void printErr(const std::string &str, bool newline)
{
    std::cerr << str;
    if (newline)
        std::cerr << std::endl;
}

void trim(std::string &s)
{
    std::string::iterator it;

    it = s.begin();
    while (it != s.end() && std::isspace(static_cast<unsigned char>(*it)))
        ++it;
    s.erase(s.begin(), it);

    if (s.empty()) return;
    it = s.end() - 1;
    while (it != s.begin() && std::isspace(static_cast<unsigned char>(*it)))
        --it;
    s.erase(it + 1, s.end());
}