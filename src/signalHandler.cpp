#include "signalHandler.hpp"

void signalHandler::closeProgram(int signalNumber) {
  std::cout << "Shuting down" << std::endl;
  exit(signalNumber);
}
