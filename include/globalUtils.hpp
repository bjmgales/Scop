#include <iostream>

void printArgs(int argc, char **argv);

bool endsWith(const std::string &str, const std::string &suffix);

void print();
template <typename... Args>
void print(const std::string &str, const Args &...rest)
{
    std::cout << str << std::endl;
    print(rest...);
}

void printErr(const std::string &str, bool newline = true);