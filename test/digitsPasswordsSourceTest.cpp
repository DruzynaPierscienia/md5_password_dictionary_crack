#include "gtest/gtest.h"
#include "digitsPasswordsSource.cpp"
#include <regex>

TEST (digitsPasswordsSourceTest, PasswordLengthShouldBeGreaterThanZero) {
  digitsPasswordsSource passwordsSource;
  
  auto password = passwordsSource.getPassword();
  
  EXPECT_TRUE (password.size() > 0);
}

TEST (digitsPasswordsSourceTest, PasswordShouldBeCombinationsOfDigits) {
  digitsPasswordsSource passwordsSource;
  
  auto password = passwordsSource.getPassword();
  std::regex everythingIsADigit("[[:d:]]+");
  
  auto passwordContainsOnlyDigits = std::regex_match(password, everythingIsADigit);
  
  EXPECT_TRUE (passwordContainsOnlyDigits);
}

TEST (digitsPasswordsSourceTest, CheckingIfNumbersAfterGetPasswordIsDifferent) {
  digitsPasswordsSource passwordSource;

  auto password1 = passwordSource.getPassword();
  auto password2 = passwordSource.getPassword();

  EXPECT_TRUE (password1 != password2);
}

TEST (digitsPasswordsSourceTest, CheckingIfHaveDataIsAlwaysTrue) {
  digitsPasswordsSource passwordSource;

  auto isThereData = false;
  
  for(unsigned int i = 0; i < 10; i++)
    passwordSource.haveData();

  isThereData = passwordSource.haveData();

  EXPECT_TRUE (isThereData);
}

