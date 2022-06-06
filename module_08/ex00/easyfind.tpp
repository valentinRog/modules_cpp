#include "easyfind.hpp"

template <typename T> typename T::const_iterator easyfind( T const &cont, int n ) {
    return std::find( cont.begin(), cont.end(), n );
}
