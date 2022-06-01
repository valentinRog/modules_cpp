#include "ScalarConverter.hpp"

template <typename T> T StringToNumber( const std::string &numberAsString ) {
    T valor;

    std::stringstream stream( numberAsString );
    stream >> valor;
    if ( stream.fail() ) {
        std::runtime_error e( numberAsString );
        throw e;
    }
    return valor;
}


int main( int argc, char **argv ) {
    if ( argc == 2 ) { std::cout << argv[1] << std::endl; }

	std::stringstream ss;

	ss << "42.4";

	float x;

	ss >> x;

	std::cout << x << std::endl;
	char number= StringToNumber<char>("'c'");
	std::cout << number << std::endl;

	std::cout << 7.9f/0 << std::endl;

    return 0;
}
