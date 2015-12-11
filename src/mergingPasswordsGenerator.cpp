#include "mergingPasswordsGenerator.hpp"

mergingPasswordsGenerator::mergingPasswordsGenerator(std::string const& fileName, lambdaType passwordsConverter)
    :dictionaryPasswordsSource(fileName), passwordLetterCaseConverter(passwordsConverter), numberToMerge() {}

bool mergingPasswordsGenerator::haveData() {
  return true;
}

std::string mergingPasswordsGenerator::getPassword() {
  if(dictionaryPasswordsSource::haveData()) {
    std::string passwordBeforeConversion = dictionaryPasswordsSource::getPassword();
    return passwordLetterCaseConverter(passwordBeforeConversion) + std::to_string(numberToMerge);
  }
  else {
    dictionaryPasswordsSource::clear();
    numberToMerge++;
    std::string passwordBeforeConversion = dictionaryPasswordsSource::getPassword();
    return passwordLetterCaseConverter(passwordBeforeConversion) + std::to_string(numberToMerge);
  }
}
