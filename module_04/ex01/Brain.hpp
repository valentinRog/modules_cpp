#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

private:
    static int const _nIdeas = 100;
	std::string _ideas[_nIdeas];
    int _i;

public:
    Brain();
    Brain( Brain const &other );
    Brain &operator=( Brain const &other );
    virtual ~Brain();

    void add(std::string const &idea);

    virtual void print(std::ostream &os) const;
};

std::ostream &operator<<( std::ostream &os, Brain const & brain);

#endif
