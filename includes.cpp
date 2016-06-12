#include "includes.h"
#include <iostream>

void printCharMultiTimes(char charToBePrinted, int numOfTimes) {
  for (int i = 0; i < numOfTimes; i++) {
    std::cout << charToBePrinted;
  }
}
