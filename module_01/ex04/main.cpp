#include <fstream>
#include <iostream>
#include <string>

int main( int argc, char **argv ) {
	if ( argc != 4 ) {
		std::cerr << "Error: 3 positional arguments required" << std::endl;
		return 1;
	}

	std::string filename( argv[1] );
	std::string oldString( argv[2] );
	std::string newString( argv[3] );

	if ( oldString.empty() ) {
		std::cerr << "Error: string to replace shouldn't be empty" << std::endl;
		return 1;
	}

	std::ifstream iStream( filename.c_str() );
	if ( !iStream ) {
		std::cerr << "Error: Unable to open file: " << filename << std::endl;
		return 1;
	}

	std::ofstream oStream( ( filename + ".replace" ).c_str() );
	if ( !iStream ) {
		std::cerr << "Error: Unable to open file: " << filename + ".replace"
				  << std::endl;
		return 1;
	}

	std::string buffer;
	char		c;
	while ( iStream.get( c ) ) { buffer += c; }

	std::string::size_type index = buffer.find( oldString );
	while ( index != std::string::npos ) {
		buffer.erase( index, oldString.size() );
		buffer.insert( index, newString );
		index += newString.size();
		index = buffer.find( oldString, index );
	}
	oStream << buffer;

	return 0;
}
