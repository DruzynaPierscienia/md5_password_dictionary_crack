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
