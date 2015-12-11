#include "lettersConverter.hpp"

std::string lettersConverter::onlyFirstLetterUpperCase(std::string & word) {
  auto lowerCaseWord = everyLetterToLowerCase(word);
  std::transform(lowerCaseWord.begin(), lowerCaseWord.begin()+1, lowerCaseWord.begin(), ::toupper);
  return lowerCaseWord;
}

std::string lettersConverter::everyLetterToUpperCase(std::string & word) {
  std::transform(word.begin(), word.end(), word.begin(), ::toupper);
  return word;
}

std::string lettersConverter::everyLetterToLowerCase(std::string & word) {
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  return word;
}
