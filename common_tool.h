#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace CommonTool {
template <class T>
std::string Join(const std::vector<T> &in, const std::string &sep) {
  std::stringstream stream;

  bool first = true;
  for (const auto &s : in) {
    if (first)
      first = false;
    else
      stream << sep;

    stream << s;
  }

  return stream.str();
}

// 打印vector
template <typename T>
void PrintVector(const std::string note_str, const std::vector<T> &input_vec) {
  std::cout << note_str << ":" << std::endl;
  std::cout << Join<T>(input_vec, ",") << std::endl;
}
}  // namespace CommonTool