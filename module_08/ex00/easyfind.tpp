#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind( T &cont, int n ) {
    return std::find( cont.begin(), cont.end(), n );
}
