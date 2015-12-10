#include "gtest/gtest.h"
#include "lettersConverter.cpp"
#include <string>

TEST (lettersConverter, onlyFirstLetterShouldBeUpperCase) {
  lettersConverter converter;
  std::string word("aLa");
  std::string desiredWord("Ala");
  
  auto resultWord = converter.onlyFirstLetterUpperCase(word);
  
  EXPECT_TRUE (resultWord == desiredWord);
}

TEST (lettersConverter, EveryLetterShouldBeUpperCase) {
  lettersConverter converter;
  std::string word("aLa");
  std::string desiredWord("ALA");
  
  auto resultWord = converter.everyLetterToUpperCase(word);
  
  EXPECT_TRUE (resultWord == desiredWord);
}

TEST (lettersConverter, EveryLetterShouldBeLowerCase) {
  lettersConverter converter;
  std::string word("aLa");
  std::string desiredWord("ala");
  
  auto resultWord = converter.everyLetterToLowerCase(word);
  
  EXPECT_TRUE (resultWord == desiredWord);
}
