#include "gtest/gtest.h"
#include "passwordBreaker.cpp"

TEST (passwordBreakerTest, breakPasswordFunctionShouldBreakThis_ReturnTrue) { 
  auto passwordToCrack {"some_password_to_crack"};
  auto hashedPasswordToMatch {"d76178a61618954ebf9670e40bad8e25"};
  
  passwordBreaker passBreaker;
  auto matchedPassword = passBreaker.breakPassword(passwordToCrack,hashedPasswordToMatch);
  
  EXPECT_TRUE (matchedPassword);
}

TEST (passwordBreakerTest, breakPasswordFunctionShouldNotBreakThis_ReturnFalse) { 
  auto passwordToCrack {"some_other_incorrect_password_to_crack"};
  auto hashedPasswordToMatch {"d76178a61618954ebf9670e40bad8e25"};
  
  passwordBreaker passBreaker;
  auto matchedPassword = passBreaker.breakPassword(passwordToCrack,hashedPasswordToMatch);
  
  EXPECT_FALSE (matchedPassword);
}
