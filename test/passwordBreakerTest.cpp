#include "gtest/gtest.h"
#include "passwordBreaker.cpp"

TEST (passwordBreakerTest, breakPasswordFunctionShouldBreakThis_ReturnMatchedPassword) { 
  auto passwordToCrack {"some_password_to_crack"};
  auto hashedPasswordToMatch {"d76178a61618954ebf9670e40bad8e25"};

  auto passwordsSourceLambdaType = [&passwordToCrack]()
      {
        return std::string(passwordToCrack);
      };
  
  passwordBreaker passBreaker {passwordsSourceLambdaType};
  auto matchedPassword = passBreaker.breakPassword(hashedPasswordToMatch);
  
  EXPECT_TRUE (matchedPassword == passwordToCrack);
}

TEST (passwordBreakerTest, breakPasswordFunctionShouldNotBreakThis_ReturnEmptyPassword) { 
  auto passwordToCrack {"some_password_to_crack"};
  auto hashedPasswordToMatch {"raaaaaaaaaaaaaaaaandom_md5_sum"};

  auto passwordsSourceLambdaType = [&passwordToCrack]()
      {
        return std::string(passwordToCrack);
      };
  
  passwordBreaker passBreaker {passwordsSourceLambdaType};
  auto matchedPassword = passBreaker.breakPassword(hashedPasswordToMatch);
  
  EXPECT_TRUE (matchedPassword == "");
}
