#pragma once

#include "md5SumGenerator.hpp"
#include <string>
#include <functional>

using passwordsSourceLambdaType = std::string();

class passwordBreaker :md5SumGenerator {
 public:
  passwordBreaker (std::function<passwordsSourceLambdaType> algorithm)
      :passwordsSource(algorithm) {}
  std::string breakPassword(std::string const& password);
 private:
  std::function<passwordsSourceLambdaType> passwordsSource;
};
