#pragma once

#include "IPasswordsSource.hpp"
#include <string>
#include <random>
#include <algorithm>

class randomWordsGenerator :public IPasswordsSource {
  std::string validCharacters;
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution;
  std::uniform_int_distribution<int> lengthDistribution;
 public:
  randomWordsGenerator(std::string const& charactersSource) :validCharacters(charactersSource), generator(), distribution(0,validCharacters.size()-1), lengthDistribution(1,13) {}
  bool haveData();
  std::string getPassword();
};
