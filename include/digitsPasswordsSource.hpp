#pragma once

#include "IPasswordsSource.hpp"

class digitsPasswordsSource : IPasswordsSource {
  unsigned long digit = 0;
 public:
  bool haveData();
  std::string getPassword();
};
