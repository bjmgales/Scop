#include <Parser.hpp>
#include <globalUtils.hpp>
#include <fstream>
std::string Parser::parse(int argc, char **argv)
{
    const std::string objPath = Parser::_parseArgs(argc, argv);

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
    {
        throw std::runtime_error("Error: Unvalid Argument.\n");
    }
    return objectFilePath;
}

std::string Parser::_parseObj(const std::string &objPath)
{
    std::ifstream file(objPath);
    if (!file)
        throw std::runtime_error("Error: file not found.\n");
    std::string line;
    std::getline(file, line);
    print(line);
}