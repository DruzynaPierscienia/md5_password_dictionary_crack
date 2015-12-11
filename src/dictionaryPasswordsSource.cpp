#include "dictionaryPasswordsSource.hpp"

dictionaryPasswordsSource::dictionaryPasswordsSource(std::string const& streamFileName)
    :inputStream{streamFileName, std::ios::in} {}

bool dictionaryPasswordsSource::haveData() {
    return inputStream.peek() != EOF;
}

void dictionaryPasswordsSource::clear() {
  inputStream.clear();
  inputStream.seekg(std::ios_base::beg);
}

std::string dictionaryPasswordsSource::getPassword() {
  std::string tempLine {};
  std::getline(inputStream,tempLine);
  return tempLine;
}
