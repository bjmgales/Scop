extern "C"
{
#include "mlx.h"
}
#include <iostream>
#include <Parser.hpp>
#include <global_utils.hpp>

static const char *const USAGE = "  Usage: \"./Scop file.obj\".";
int main(int argc, char **argv)
{
  try
  {
    Parser::parseArgs(argc, argv);
  }
  catch (const std::exception &error)
  {
    printErr(error.what(), false);
    printErr(USAGE);
    return 1;
  }

  void *mlx = mlx_init();
  if (!mlx)
    return 1;
  void *win = mlx_new_window(mlx, 200, 100, (char *)"OK");
  mlx_loop(mlx);
}
