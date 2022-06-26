#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {

private:
    void debug();
    void info();
    void warning();
    void error();

    static int const         _levelCount;
    static std::string const _levelStr[];

    enum e_level { DEBUG, INFO, WARNING, ERROR };

public:
    int get_level_index( std::string const &level );

    void complain( std::string const &level );
    void complainFilter( std::string const &level );
};

#endif
