#pragma once

#include "IPasswordsSource.hpp"
#include "IPasswordsOutput.hpp"
#include "passwordBreaker.hpp"

#include <vector>
#include <algorithm>

class algorithmPasswordBreaker :passwordBreaker {
  std::vector<std::string> hashedPasswords;
  IPasswordsSource& passwordsSource;
  IPasswordsOutput& passwordsOutput;
 public:
  algorithmPasswordBreaker(std::vector<std::string>, IPasswordsSource&, IPasswordsOutput&);
  void run();
};
