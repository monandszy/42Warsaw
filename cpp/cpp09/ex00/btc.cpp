#include "btc.hpp"

void log(const std::string& s) { std::cout << "[" << s << "]" << std::endl; }

void pair(std::map<std::string, double>& data,
          std::multimap<std::string, double>& input) {
  for (std::multimap<std::string, double>::iterator it = input.begin();
       it != input.end(); ++it) {
    std::string key = it->first;
    double value = it->second;
    std::multimap<std::string, double>::iterator res = data.find(key);
    if (res == data.end()) {
      log("WARN: key not found");
      std::string prevkey = "";
      for (std::multimap<std::string, double>::iterator it = input.begin();
           it != input.end(); ++it) {
        if (key < it->first) break;
        prevkey = it->first;
      }
      if (prevkey.empty()) {
        log("ERROR: previous key not found");
        continue;
      }
      log("Found:" + prevkey);
      key = prevkey;
    }
    double target = value * res->second;
    std::cout << "[" << key << "]" << " => " << value << " = " << target
              << std::endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    log("ERROR: invalid argument count");
    return 1;
  }
  std::map<std::string, double> data;
  std::multimap<std::string, double> input;
  parse_file(data, "data.csv", ",");
  parse_file(input, argv[1], " | ");
  pair(data, input);
}