#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>

Base *generate();
void  identify( Base *p );
void  identify( Base &p );

#endif
