#include "algorithmPasswordBreaker.hpp"

algorithmPasswordBreaker::algorithmPasswordBreaker(std::vector<std::string> passwords, IPasswordsSource& passwordsSourceAlgorithms, IPasswordsOutput& output)
    :passwordBreaker(), hashedPasswords(passwords), passwordsSource(passwordsSourceAlgorithms), passwordsOutput(output) {}


void algorithmPasswordBreaker::run() {
  while( passwordsSource.haveData() ) {
    auto readedPassword = passwordsSource.getPassword();
    auto outputIter = std::find_if(hashedPasswords.begin(),hashedPasswords.end(), [this,&readedPassword](std::string const& hashedPassword)
                                   {
                                     return passwordBreaker::breakPassword(readedPassword,hashedPassword);
                                   });
    bool passwordMatched = outputIter != hashedPasswords.end();

    if(passwordMatched)
      passwordsOutput.sendPassword(readedPassword);
  }
}
