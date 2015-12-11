#include "gtest/gtest.h"
#include "lettersConverter.cpp"
#include <string>

TEST (lettersConverter, onlyFirstLetterShouldBeUpperCase) {
  std::string word("aLa");
  std::string desiredWord("Ala");
  
  auto resultWord = lettersConverter::onlyFirstLetterUpperCase(word);
  
  EXPECT_TRUE (resultWord == desiredWord);
}

TEST (lettersConverter, EveryLetterShouldBeUpperCase) {
  std::string word("aLa");
  std::string desiredWord("ALA");
  
  auto resultWord = lettersConverter::everyLetterToUpperCase(word);
  
  EXPECT_TRUE (resultWord == desiredWord);
}

TEST (lettersConverter, EveryLetterShouldBeLowerCase) {
  std::string word("aLa");
  std::string desiredWord("ala");
  
  auto resultWord = lettersConverter::everyLetterToLowerCase(word);
  
  EXPECT_TRUE (resultWord == desiredWord);
}
