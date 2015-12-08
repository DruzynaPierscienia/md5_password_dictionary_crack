#include "dictionaryPasswordsSource.hpp"

dictionaryPasswordsSource::dictionaryPasswordsSource(std::string const& streamFileName)
    :inputStream{streamFileName} {}

bool dictionaryPasswordsSource::haveData() {
    return inputStream.peek() != EOF;
}

std::string dictionaryPasswordsSource::getPassword() {
  std::string tempLine {};
  std::getline(inputStream,tempLine);
  return tempLine;
}
