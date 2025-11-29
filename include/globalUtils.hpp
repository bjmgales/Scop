#include <iostream>

void printArgs(int argc, char **argv);

bool endsWith(const std::string &suffix, const std::string &str);

void print(const std::string &str);
void printErr(const std::string &str, bool newline = true);