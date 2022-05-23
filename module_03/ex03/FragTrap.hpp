#ifndef FLAG_TRAP_HPP
#define FLAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
	FragTrap();
    FragTrap( std::string const name );
    FragTrap( FragTrap const &other );
    FragTrap &operator=( FragTrap const &other );
    ~FragTrap();

	void attack( std::string const &target );

	void highFivesGuys();
};

#endif
