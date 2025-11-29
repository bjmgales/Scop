#include <globalUtils.hpp>

bool endsWith(const std::string &suffix, const std::string &str)
{
    if (suffix.size() > str.size())
        return false;
    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void printArgs(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "Arg " << i << ": " << argv[i] << std::endl;
    }
}

void print(const std::string &str)
{
    std::cout << str << std::endl;
}

void printErr(const std::string &str, bool newline)
{
    std::cerr << str;
    if (newline)
        std::cerr << std::endl;
}