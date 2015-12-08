#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "algorithmPasswordBreaker.cpp"
#include "IPasswordsSource.hpp"
#include "IPasswordsOutput.hpp"

using testing::_;

class passwordsOutputMock :public IPasswordsOutput {
 public:
  MOCK_METHOD1(sendPassword,void(std::string const&));
};

class passwordsSourceMock :public IPasswordsSource {
  unsigned int i = 0;
 public:
  bool haveData();
  std::string getPassword();
};

bool passwordsSourceMock::haveData() {
  if(i < 2)  return true;
  else    return false;
}

std::string passwordsSourceMock::getPassword() {
  if(i++ == 0)    return "xxx";
  else    return "zzz";
}

TEST (algorithmPasswordBreaker, algorithmShouldFindOnePassword) {
  std::vector<std::string> hashedPasswords {"f561aaf6ef0bf14d4208bb46a4ccb3ad","f0a4058fd33489695d53df156b77c724"};
  
  passwordsSourceMock passwordsSource;
  passwordsOutputMock passwordsOutput;

  algorithmPasswordBreaker passwordsBreaker(hashedPasswords, passwordsSource, passwordsOutput);

  EXPECT_CALL(passwordsOutput,sendPassword("xxx"))
      .Times(1);
  
  passwordsBreaker.run();
}
