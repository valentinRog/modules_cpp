#include "Harl.hpp"

void Harl::debug() {
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info() {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning() {
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  const int levelCount = 4;
  void (Harl::*levelFun[levelCount])(void) = {&Harl::debug, &Harl::info,
                                              &Harl::warning, &Harl::error};
  std::string levelStr[levelCount] = {"debug", "info", "warning", "error"};

  for (int i = 0; i < levelCount; i++) {
    if (level == levelStr[i]) {
      (this->*levelFun[i])();
      break;
    }
  }
}
