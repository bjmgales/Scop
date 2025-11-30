#include <fstream>
#include <string>

class Parser
{
public:
  static std::string parse(int argc, char **argv);

private:
  static std::string _parseArgs(int argc, char **argv);
  static std::string _parseObj(const std::string &objPath);
};