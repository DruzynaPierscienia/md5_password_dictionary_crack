#include "md5HashedPasswordsReader.hpp"

md5HashedPasswordsReader::md5HashedPasswordsReader(std::string const& streamFileName)
    :inputStream{streamFileName} {}

bool md5HashedPasswordsReader::haveMoreData() {
  return inputStream.peek() != EOF;
}

std::string md5HashedPasswordsReader::getHashedPassword() {
  std::string tempLine {};
  std::getline(inputStream,tempLine);
  return tempLine;
}
