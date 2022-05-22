#ifndef FLAG_TRAP_HPP
#define FLAG_TRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {

public:
	FlagTrap();
    FlagTrap( std::string const name );
    FlagTrap( FlagTrap const &other );
    FlagTrap &operator=( FlagTrap const &other );
    ~FlagTrap();

	void attack( const std::string &target );

    void guardGate();
	void highFivesGuys();
};

#endif
