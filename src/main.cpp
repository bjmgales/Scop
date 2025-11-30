extern "C"
{
#include "mlx.h"
}

#include <exception>
#include <tuple>
#include <vector>
#include <fstream>
#include <Object.hpp>

static const char *const USAGE = "  Usage: \"./Scop file.obj\".";

std::vector<std::string> parseArgs(int argc, char **argv)
{

  if (argc != 2)
    throw std::runtime_error("Error: Missing or unvalid arguments.\n");

  std::string objectFilePath = argv[1];
  if (!endsWith(objectFilePath, ".obj"))
    throw std::runtime_error("Error: Unvalid Argument.\n");

  std::ifstream file;
  file.open(objectFilePath);
  if (!file)
    throw std::runtime_error("Error: file was not found.\n");

  std::string line;
  std::vector<std::string> fileContent;
  while (std::getline(file, line))
  {
    print(line);
    fileContent.push_back(line);
  }
  return fileContent;
}

std::tuple<void *, void *> initMlx(unsigned int sizeX, unsigned int sizeY)
{
  void *mlx = mlx_init();
  if (!mlx)
    throw std::runtime_error("Error: Could not start mlx.");
  void *win = mlx_new_window(mlx, sizeX, sizeY, (char *)"Scop");
  return {mlx, win};
}

int main(int argc, char **argv)
{
  std::vector<std::string> objContent;
  try
  {
    objContent = parseArgs(argc, argv);
  }
  catch (const std::exception &error)
  {
    printErr(error.what(), false);
    printErr(USAGE);
    return 1;
  }

  std::tuple<void *, void *> t = initMlx(200, 200);
  void *mlx = std::get<0>(t);
  void *win = std::get<1>(t);
  Object obj = Object(objContent);
  mlx_loop(mlx);
}
