#include <thread>
#include "userPasswordsLoader.hpp"
#include "mergingPasswordsGenerator.hpp"
#include "lettersConverter.hpp"
#include "dictionaryPasswordsSource.hpp"
#include "passwordsBreaker.hpp"
#include "screenPrinter.hpp"

int main() {
  
  std::string hashedPasswordsFileName;  
  std::cin >> hashedPasswordsFileName;

  std::string dictionaryFileName;
  std::cin >> dictionaryFileName;
  
  userPasswordsLoader passwordsLoader(hashedPasswordsFileName);
  const auto hashedPasswords = passwordsLoader.loadUserPasswords();

  screenPrinter printer;
  
  std::thread firstUpperThread([&]()
                               {
                                 mergingPasswordsGenerator generator(dictionaryFileName, [](std::string & password)
                                                                     {
                                                                       return lettersConverter::onlyFirstLetterUpperCase(password);
                                                                     });
                                 passwordsBreaker breaker(hashedPasswords, generator, printer);
                                 breaker.run();
                               });
  
  std::thread everyUpperThread([&]()
                               {
                                 mergingPasswordsGenerator generator(dictionaryFileName, [](std::string & password)
                                                                     {
                                                                       return lettersConverter::everyLetterToUpperCase(password);
                                                                     });
                                 passwordsBreaker breaker(hashedPasswords, generator, printer);
                                 breaker.run();
                               });

  std::thread everyLowerThread([&]()
                               {
                                 mergingPasswordsGenerator generator(dictionaryFileName, [](std::string & password)
                                                                     {
                                                                       return lettersConverter::everyLetterToUpperCase(password);
                                                                     });
                                 passwordsBreaker breaker(hashedPasswords, generator, printer);
                                 breaker.run();
                               });

  dictionaryPasswordsSource dictionaryGenerator(dictionaryFileName);
  passwordsBreaker breaker(hashedPasswords, dictionaryGenerator, printer);
  breaker.run();

  firstUpperThread.join();
  everyUpperThread.join();
  everyLowerThread.join();
}
