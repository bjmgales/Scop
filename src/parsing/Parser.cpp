#include <Parser.hpp>
#include <globalUtils.hpp>
#include <algorithm>

static const char *const TOKENS[4] = {"v", "vn", "vt", "f"};
std::string Parser::parse(int argc, char **argv)
{
    const std::string objPath = Parser::_parseArgs(argc, argv);
    Parser::_parseObj(objPath);
    return objPath;
}

std::string Parser::_parseArgs(int argc, char **argv)
{
    if (argc != 2)
    {
        throw std::runtime_error("Error: Missing or unvalid arguments.\n");
    }

    std::string objectFilePath = argv[1];
    if (!endsWith(objectFilePath, ".obj"))
        throw std::runtime_error("Error: Unvalid Argument.\n");
    return objectFilePath;
}

bool isEmpty(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), [](unsigned char c)
                       { return std::isspace(c); });
}

bool isComment(const std::string &str)
{
    return str[0] == '#';
}

bool isCompliant(const std::string &str)
{
    if (str.size() < 2)
        return false;
    if (str[0] != 'v' && str[0] != 'f')
        return false;
    if (str[0] == 'v' && (str[1] != 't' && str[1] != 'n'))
        return false;
}

std::string Parser::_parseObj(const std::string &objPath)
{
    std::ifstream file;
    file.open(objPath);
    if (!file)
        throw std::runtime_error("Error: file was not found.\n");
    std::string line;
    while (std::getline(file, line))
    {
        if (isComment(line))
            continue;
        else if (isEmpty(line))
            continue;
        else if (!isCompliant(line))
            throw std::runtime_error("Error: line incorrectly formatted.\n");
    }
    return line;
}