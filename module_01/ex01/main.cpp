#include "Zombie.hpp"

int main(void) {
  int const N = 5;
  Zombie *horde = zombieHorde(N, "Yo");
  for (int i = 0; i < N; i++) {
    horde[i].announce();
  }
  std::cout << std::endl;
  delete[] horde;
  return 0;
}
