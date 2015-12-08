#pragma once

#include "md5SumGenerator.hpp"

#include <string>
#include <functional>

class passwordBreaker :md5SumGenerator {
 public:
  bool breakPassword (std::string const& password, std::string const& hashedPassword);
};
