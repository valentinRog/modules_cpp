#include <iostream>
#include <string>

# define DEFAULT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
	std::string msg("");

	if (argc == 1)
		msg = DEFAULT_MSG;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			msg += argv[i];
		for (std::string::iterator it = msg.begin(); it < msg.end(); it++)
			*it = std::toupper(*it);
	}
	std::cout << msg << std::endl;
	return 0;
}
