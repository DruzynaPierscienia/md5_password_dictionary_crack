#pragma once

#include <string>

class IPasswordsSource {
 public:
  virtual bool haveData() = 0;
  virtual std::string getPassword() = 0;  
};
