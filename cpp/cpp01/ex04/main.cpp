#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

std::string read_all(std::ifstream &in)
{
  std::stringstream buffer;
  buffer << in.rdbuf();
  return buffer.str();
}

std::string replace(
  std::string content,
  std::string s1,
  std::string s2
){
  std::regex target(s1);

  std::string result = std::regex_replace(content, target, s2);
  return result;
}

void write(std::ofstream &out, std::string content)
{
  out << content;
}

int main(int argc, char *argv[])
{
  if (argc == 4)
  {
    std::ifstream inFile(argv[1]);
    std::string content = read_all(inFile);
    inFile.close();

    content = replace(content, argv[2], argv[3]);

    std::string fn = argv[1];
    std::ofstream outFile((fn + "replaced").c_str());
    write(outFile, content);
    outFile.close();
  } else
    std::cout << "Invalid arguments";
}