#include "userPasswordsLoader.hpp"

alignas(64) std::vector<std::string> userPasswordsLoader::loadUserPasswords() {
  alignas(64) std::vector<std::string> passwords;
  while(dictionaryPasswordsSource::haveData())
    passwords.push_back( dictionaryPasswordsSource::getPassword() );
  return passwords;
}
