#pragma once

#include "md5SumGenerator.hpp"

#include <string>

class passwordsMatcher :md5SumGenerator {
 public:
  bool matchPassword (std::string const& password, std::string const& hashedPassword);
};
