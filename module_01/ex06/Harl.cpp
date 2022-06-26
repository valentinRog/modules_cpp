#include "Harl.hpp"

/* -------------------------------------------------------------------------- */

int const         Harl::_levelCount = 4;
std::string const Harl::_levelStr[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

/* -------------------------------------------------------------------------- */

void Harl::debug() {
    std::cout
        << "[ DEBUG ]" << std::endl
        << "I love having extra bacon for my "
           "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl
              << "I cannot believe adding extra bacon costs more money. You "
                 "didn't put "
                 "enough bacon in my burger! If you did, I wouldn't be asking "
                 "for more!"
              << std::endl;
}

void Harl::warning() {
    std::cout
        << "[ WARNING ]" << std::endl
        << "I think I deserve to have some extra bacon for free. I've been "
           "coming for years whereas you started working here since last month."
        << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl
              << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

/* -------------------------------------------------------------------------- */

int Harl::get_level_index( std::string const &level ) {
    for ( int i = 0; i < _levelCount; i++ ) {
        if ( level == _levelStr[i] ) { return i; }
    }
    return -1;
}

/* -------------------------------------------------------------------------- */

void Harl::complain( std::string const &level ) {
    void ( Harl::*levelFun[] )( void )
        = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for ( int i = 0; i < _levelCount; i++ ) {
        if ( level == _levelStr[i] ) {
            ( this->*levelFun[i] )();
            break;
        }
    }
}

void Harl::complainFilter( std::string const &level ) {
    switch ( get_level_index( level ) ) {
    case DEBUG:
        debug();
        // fall through
    case INFO:
        info();
        // fall through
    case WARNING:
        warning();
        // fall through
    case ERROR:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
