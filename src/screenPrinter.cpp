#include "screenPrinter.hpp"

void screenPrinter::sendPassword(std::string const& password) {
  std::lock_guard<std::mutex> locker(mutex);
  std::cout << password << std::endl;
}

