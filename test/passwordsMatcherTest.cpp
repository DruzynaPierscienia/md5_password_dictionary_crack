#include "gtest/gtest.h"
#include "passwordsMatcher.cpp"

TEST (passwordsMatcherTest, matchPasswordFunctionShouldBreakThis_ReturnTrue) { 
  auto passwordToCrack = "some_password_to_crack";
  auto hashedPasswordToMatch = "d76178a61618954ebf9670e40bad8e25";
  
  passwordsMatcher passMatcher;
  auto matchedPassword = passMatcher.matchPassword(passwordToCrack,hashedPasswordToMatch);
  
  EXPECT_TRUE (matchedPassword);
}

TEST (passwordsMatcherTest, matchPasswordFunctionShouldNotBreakThis_ReturnFalse) { 
  auto passwordToCrack = "some_other_incorrect_password_to_crack";
  auto hashedPasswordToMatch = "d76178a61618954ebf9670e40bad8e25";
  
  passwordsMatcher passMatcher;
  auto matchedPassword = passMatcher.matchPassword(passwordToCrack,hashedPasswordToMatch);
  
  EXPECT_FALSE (matchedPassword);
}
