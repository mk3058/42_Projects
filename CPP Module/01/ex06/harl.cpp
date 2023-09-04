#include "harl.hpp"

void Harl::debug() {
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
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
  std::string cmd[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
                             &Harl::error};

  for (int i = 0; i <= 4; i++) {
    if (i == 4) {
      std::cout << "Invalid Argument " + level << std::endl;
      return;
    }
    if (level == cmd[i]) (this->*func[i])();
  }
}

void Harl::harlFilter(std::string level) {
  std::string cmd[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int i = 0;

  for (i = 0; i < 4; i++) {
    if (level == cmd[i]) break;
  }

  switch (i) {
    case 0:
      std::cout << "[ DEBUG ]" << std::endl;
      this->debug();
      std::cout << std::endl;
      __attribute__((fallthrough));
    case 1:
      std::cout << "[ INFO ]" << std::endl;
      this->info();
      std::cout << std::endl;
      __attribute__((fallthrough));
    case 2:
      std::cout << "[ WARNING ]" << std::endl;
      this->warning();
      std::cout << std::endl;
      __attribute__((fallthrough));
    case 3:
      std::cout << "[ ERROR ]" << std::endl;
      this->error();
      std::cout << std::endl;
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
  }
}