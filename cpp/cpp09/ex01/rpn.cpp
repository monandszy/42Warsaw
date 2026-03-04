/*
N1 N2 O
No operator hierarchy

N - Push to Stack
O - Pop 2, apply, push result.
*/

#include <iostream>
#include <stack>

void log(const std::string& s) { std::cout << "[" << s << "]" << std::endl; }

void safe_pop(std::stack<int>& s) {
  if (s.size() == 0) {
    throw std::runtime_error("ERROR: Cannot pop");
  }
  s.pop();
}

int safe_top(std::stack<int>& s) {
  if (s.size() == 0) {
    throw std::runtime_error("ERROR: Cannot top");
  }
  return s.top();
}

std::pair<int, int> pop_two(std::stack<int>& s) {
  int i2 = safe_top(s);
  safe_pop(s);
  int i1 = safe_top(s);
  safe_pop(s);
  return (std::make_pair(i1, i2));
}

void loop_equation(std::stack<int>& s, char* m) {
  for (int i = 0; m[i]; i++) {
    if (m[i] == ' ') {
      continue;
    } else if (isdigit(m[i])) {
      s.push(m[i] - '0');
    } else if (m[i] == '+') {
      std::pair<int, int> i = pop_two(s);
      s.push(i.first + i.second);
    } else if (m[i] == '-') {
      std::pair<int, int> i = pop_two(s);
      s.push(i.first - i.second);
    } else if (m[i] == '*') {
      std::pair<int, int> i = pop_two(s);
      s.push(i.first * i.second);
    } else if (m[i] == '/') {
      std::pair<int, int> i = pop_two(s);
      s.push(i.first / i.second);
    } else {
      log("ERROR: unknown character");
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    log("invalid argument count");
    return 1;
  }
  std::stack<int> s;
  char* m = argv[1];
  try {
    loop_equation(s, m);
    if (s.size() != 1) {
      throw std::runtime_error("Invalid result");
    }
    std::cout << s.top() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}