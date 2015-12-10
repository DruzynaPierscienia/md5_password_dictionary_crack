#include "lettersConverter.hpp"

std::string lettersConverter::firstLetterToUpperCase(std::string word) {
  std::transform(word.begin(), word.begin()+1, word.begin(), ::toupper);

  return word;
}

std::string lettersConverter::everyLetterToUpperCase(std::string word) {
  std::transform(word.begin(), word.end(), word.begin(), ::toupper);

  return word;
}

std::string lettersConverter::everyLetterToLowerCase(std::string word) {
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  
  return word;
}
