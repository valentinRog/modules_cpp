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

	static int const		 _levelCount;
	static std::string const _levelStr[];

  public:
	void complain( std::string level );
};

#endif
