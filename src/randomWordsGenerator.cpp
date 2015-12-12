#include "randomWordsGenerator.hpp"

bool randomWordsGenerator::haveData() {
  return true;
}

std::string randomWordsGenerator::getPassword() {
  std::string randomPassword;
  std::generate_n(std::back_inserter(randomPassword), lengthDistribution(generator), [&]()
                  {
                    return validCharacters[distribution(generator)];
                  });
  return randomPassword;
}

