#include <globalUtils.hpp>

bool endsWith(const std::string &str, const std::string &suffix)
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