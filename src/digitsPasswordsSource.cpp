#include "digitsPasswordsSource.hpp"

bool digitsPasswordsSource::haveData() {
  return true;
}

std::string digitsPasswordsSource::getPassword() {
  return std::to_string(digit++);
}

// TODO: Calluje getPassword() potem znowu, patrze czy zwrocone wartosci sa rozne


// TODO: W petli calluje haveData() x10, patrze czy ostatni jest true
