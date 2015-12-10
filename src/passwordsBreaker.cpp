#include "passwordsBreaker.hpp"

passwordsBreaker::passwordsBreaker(std::vector<std::string> const& passwords, IPasswordsSource& passwordsSourceAlgorithms, IPasswordsOutput& output)
    :passwordsMatcher(), hashedPasswords(passwords), passwordsSource(passwordsSourceAlgorithms), passwordsOutput(output) {}


void passwordsBreaker::run() {
  while( passwordsSource.haveData() ) {
    auto readedPassword = passwordsSource.getPassword();
    auto outputIter = std::find_if(hashedPasswords.begin(),hashedPasswords.end(), [this,&readedPassword](std::string const& hashedPassword)
                                   {
                                     return passwordsMatcher::matchPassword(readedPassword,hashedPassword);
                                   });
    bool passwordMatched = outputIter != hashedPasswords.end();

    if(passwordMatched)
      passwordsOutput.sendPassword(readedPassword + " " + *outputIter);
  }
}
