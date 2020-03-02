#include "random.h"

#include <cstdlib>

double Random::uniform_double () {
  return static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
}

int Random::uniform_int (int n) {
  return rand() % n;
}
