#include <Parser.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <global_utils.hpp>

void Parser::parseArgs(int argc, char **argv)
{
    if (argc != 2)
    {
        throw std::invalid_argument("Error: Missing or unvalid arguments.\n");
    }

    std::string objectFilePath = argv[1];

    if (!endsWith(objectFilePath, ".obj"))
    {
        throw std::invalid_argument("Error: Unvalid Argument.\n");
    }
}