#pragma once

#include "IPasswordsOutput.hpp"
#include <iostream>
#include <string>
#include <mutex>

class screenPrinter :public IPasswordsOutput {
  std::mutex mutex;
 public:
  void sendPassword(std::string const& password);	
};

