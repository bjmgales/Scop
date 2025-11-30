#include <iostream>
#include <vector>
void printArgs(int argc, char **argv);

bool startsWith(const std::string &str, const std::string &prefix);
bool endsWith(const std::string &str, const std::string &suffix);

void print();

template <typename T, typename... Args>
void print(const T&str, const Args &...rest)
{
    std::cout << str << std::endl;
    print(rest...);
}

template <typename T>
void print(const std::vector<T> vec)
{
    for (const T &v : vec)
        print(v);
};

void printErr(const std::string &str, bool newline = true);

void trim(std::string &str);