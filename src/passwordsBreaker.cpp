#include "passwordsBreaker.hpp"

passwordsBreaker::passwordsBreaker(std::vector<std::string> const& passwords, IPasswordsSource& passwordsSourceAlgorithms, IPasswordsOutput& output)
    :md5SumGenerator(), hashedPasswords(passwords), passwordsSource(passwordsSourceAlgorithms), passwordsOutput(output) {}


void passwordsBreaker::run() {
  while( passwordsSource.haveData() ) {
    auto readedPassword = passwordsSource.getPassword();
    auto hashedPassword = md5SumGenerator::createMd5Sum(readedPassword);
        
    auto outputIter = std::find(hashedPasswords.begin(),hashedPasswords.end(),hashedPassword);
    bool passwordMatched = outputIter != hashedPasswords.end();

    if(passwordMatched)
      passwordsOutput.sendPassword(readedPassword + " " + *outputIter);
  }
}
