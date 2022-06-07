#ifndef SERIALIZE_H
#define SERIALIZE_H

#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize( Data *ptr );
Data     *deserialize( uintptr_t raw );

#endif
