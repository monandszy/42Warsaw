#include <iostream>
#include <fstream>
#include <sstream>
// #include <regex>

std::string read_all(std::ifstream &in)
{
  std::stringstream buffer;
  buffer << in.rdbuf();
  return buffer.str();
}

void replaceAll(std::string& content, std::string from, std::string to) {
  size_t pos = content.find(from);
  while (pos != std::string::npos) {
    content.erase(pos, from.length()); 
    content.insert(pos, to);
    pos = content.find(from, pos + to.length());
  }
}

// std::string replace(
//   std::string content,
//   std::string s1,
//   std::string s2
// ){
//   std::regex target(s1);

//   std::string result = std::regex_replace(content, target, s2);
//   return result;
// }

void write(std::ofstream &out, std::string &content)
{
  out << content;
}

int main(int argc, char *argv[])
{
  if (argc == 4)
  {
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open())
      return(std::cout << "Could not open input file" << std::endl, 1);
    std::string content = read_all(inFile);
    inFile.close();

    replaceAll(content, argv[2], argv[3]);

    std::string fn = argv[1];
    std::ofstream outFile((fn + ".replaced").c_str());
    if (!outFile.is_open())
      return(std::cout << "Could not open output file" << std::endl, 1);
    write(outFile, content);
    outFile.close();
  } else
    return(std::cout << "Invalid arguments" << std::endl, 1);
}