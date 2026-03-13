#include "btc.hpp"

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
  for (std::multimap<std::string, double>::iterator ii = input.begin();
       ii != input.end(); ++ii) {
    std::string key = ii->first;
    double value = ii->second;

    std::map<std::string, double>::iterator res = data.find(key);
    if (res == data.end()) {
      // log("WARN: key not found for " + it->first);
      std::string prevkey = "";
      for (std::map<std::string, double>::iterator id = data.begin();
           id != data.end(); ++id) {
        if (key < id->first) break;
        prevkey = id->first;
      }
      if (prevkey.empty()) {
        log("ERROR: previous key not found for " + ii->first);
        continue;
      }
      log("Found: " + prevkey);
      res = data.find(prevkey);
    }
    double target = (double)value * res->second;
    std::cout << "[" << key << "]"
              << " => " << std::fixed << std::setprecision(2) << res->second
              << "*" << ii->second << " = " << target << std::endl;
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
  if (argc != 3) {
    log("ERROR: invalid argument count");
    return 1;
  }
  std::map<std::string, double> data;
  std::multimap<std::string, double> input;
  std::cout << "Parsing: " << argv[1] << std::endl;
  if (parse_data(data, argv[1], ",")) return 1;
  std::cout << "-------------------------" << std::endl;
  std::cout << "Parsing: " << argv[2] << std::endl;
  if (parse_input(input, argv[2], " | ")) return 1;
  std::cout << "-------------------------" << std::endl;
  pair(data, input);
}