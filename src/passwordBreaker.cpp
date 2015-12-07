#include "passwordBreaker.hpp"

std::string passwordBreaker::breakPassword(std::string const& password) {
  auto receivedPassFromAlgorithm = passwordsSource();
  auto generatedMd5 = md5SumGenerator::createMd5Sum(receivedPassFromAlgorithm);

  if(password == generatedMd5)
    return receivedPassFromAlgorithm;
  else
    return "";
}
