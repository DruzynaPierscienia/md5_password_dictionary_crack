#pragma once

#include "IPasswordsSource.hpp"
#include "IPasswordsOutput.hpp"
#include "md5SumGenerator.hpp"

#include <vector>
#include <algorithm>

class passwordsBreaker :md5SumGenerator {
  std::vector<std::string> hashedPasswords;
  IPasswordsSource& passwordsSource;
  IPasswordsOutput& passwordsOutput;
 public:
  passwordsBreaker(std::vector<std::string> const&, IPasswordsSource&, IPasswordsOutput&);
  void run();
};
