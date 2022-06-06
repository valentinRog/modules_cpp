#ifndef ITER_TPP
#define ITER_TPP

#include <cstddef>

template <typename T>
void iter( T *array, std::size_t n, void ( *f )( T & ) ) {
    for ( std::size_t i = 0; i < n; i++ ) { f( array[i] ); }
}

#endif
