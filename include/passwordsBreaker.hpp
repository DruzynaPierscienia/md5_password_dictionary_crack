#pragma once

#include "IPasswordsSource.hpp"
#include "IPasswordsOutput.hpp"
#include "passwordsMatcher.hpp"

#include <vector>
#include <algorithm>

class passwordsBreaker :passwordsMatcher {
  std::vector<std::string> hashedPasswords;
  IPasswordsSource& passwordsSource;
  IPasswordsOutput& passwordsOutput;
 public:
  passwordsBreaker(std::vector<std::string> const&, IPasswordsSource&, IPasswordsOutput&);
  void run();
};
