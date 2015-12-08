#include "passwordBreaker.hpp"

bool passwordBreaker::breakPassword(std::string const& password, std::string const& hashedPassword) {
  return hashedPassword == md5SumGenerator::createMd5Sum(password);
}
