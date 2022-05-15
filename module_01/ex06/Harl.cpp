#include "Harl.hpp"

int const Harl::_levelCount = 4;
std::string const Harl::_levelStr[] = {"debug", "info", "warning", "error"};

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

int Harl::get_level_index(std::string level) {
  for (int i = 0; i < _levelCount; i++) {
    if (level == _levelStr[i]) {
      return i;
    }
  }
  return -1;
}

void Harl::complain(std::string level) {
  void (Harl::*levelFun[])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                    &Harl::error};

  for (int i = 0; i < _levelCount; i++) {
    if (level == _levelStr[i]) {
      (this->*levelFun[i])();
      break;
    }
  }
}

void Harl::complainFilter(int code) {
  for (int i = 0; i < _levelCount; i++) {
    if (1 << i & code) {
      std::string level = _levelStr[i];
      std::cout << "[ ";
      for (std::string::iterator it = level.begin(); it < level.end(); it++) {
        std::cout << (char)std::toupper(*it);
      }
      std::cout << " ]" << std::endl;
      complain(_levelStr[i]);
    }
  }
}
