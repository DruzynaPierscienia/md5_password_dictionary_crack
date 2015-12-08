#pragma once

#include <string>

class IPasswordsOutput {
 public:
  virtual void sendPassword(std::string const& password) = 0;
};
