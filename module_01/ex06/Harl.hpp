#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
  private:
	void					 debug();
	void					 info();
	void					 warning();
	void					 error();
	static int const		 _levelCount;
	static std::string const _levelStr[];

  public:
	int	 get_level_index( std::string level );
	void complain( std::string level );
	void complainFilter( int code );
};

#endif
