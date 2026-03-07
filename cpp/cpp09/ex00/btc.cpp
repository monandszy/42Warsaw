#include "btc.hpp"

#include <iomanip>

bool isnum(const char* str) {
  double result;
  std::istringstream i(str);
  i >> result;
  return !i.fail() && i.eof();
}

bool isdate(const char* str) {
  struct tm tm;
  if (!strptime(str, "%Y-%m-%d", &tm)) return (false);
  return (true);
}

void log(const std::string& s) { std::cout << "[" << s << "]" << std::endl; }

void pair(std::map<std::string, double>& data,
          std::multimap<std::string, double>& input) {
  for (std::multimap<std::string, double>::iterator it = input.begin();
       it != input.end(); ++it) {
    std::string key = it->first;
    double value = it->second;

    std::map<std::string, double>::iterator res = data.find(key);
    if (res == data.end()) {
      // log("WARN: key not found for " + it->first);
      std::string prevkey = "";
      for (std::map<std::string, double>::iterator it = data.begin();
           it != data.end(); ++it) {
        if (key < it->first) break;
        prevkey = it->first;
      }
      if (prevkey.empty()) {
        log("ERROR: previous key not found for " + it->first);
        continue;
      }
      log("Found: " + prevkey);
      res = it;
    }
    double target = value * res->second;
    std::cout << "[" << key << "]"
              << " => " << std::fixed << std::setprecision(2) << res->second
              << " = " << target << std::endl;
  }
}

int validate_input(double v, int i) {
  if (v < 0) {
    std::cout << "ERROR[" << i << "] negative value" << std::endl;
    return 1;
  }
  if (v > 1000) {
    std::cout << "ERROR[" << i << "] value out of bounds" << std::endl;
    return 1;
  }
  return 0;
}

int validate_data(double v, int i) {
  if (v < 0) {
    std::cout << "ERROR[" << i << "] negative value" << std::endl;
    return 1;
  }
  return 0;
}

int parse_data(std::map<std::string, double>& csv, const std::string& name,
               const std::string& s) {
  std::ifstream in(name.c_str());

  if (!in.is_open()) {
    log("ERROR: while opening file");
    return 1;
  }
  std::string f;
  getline(in, f);
  parse_ssv(csv, in, s, &validate_data);
  in.close();
  return 0;
}

int parse_input(std::multimap<std::string, double>& csv,
                const std::string& name, const std::string& s) {
  std::ifstream in(name.c_str());

  if (!in.is_open()) {
    log("ERROR: while opening file");
    return 1;
  }
  std::string f;
  getline(in, f);
  parse_ssv(csv, in, s, &validate_input);
  in.close();
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    log("ERROR: invalid argument count");
    return 1;
  }
  std::map<std::string, double> data;
  std::multimap<std::string, double> input;
  std::cout << "Parsing: "
            << "data.csv" << std::endl;
  if (parse_data(data, "data.csv", ",")) return 1;
  std::cout << "-------------------------" << std::endl;
  std::cout << "Parsing: " << argv[1] << std::endl;
  if (parse_input(input, argv[1], " | ")) return 1;
  std::cout << "-------------------------" << std::endl;
  pair(data, input);
}