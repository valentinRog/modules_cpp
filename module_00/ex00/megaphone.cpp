#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string msg("");

	if (argc == 1)
		msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			msg += argv[i];
		for (size_t i = 0; i < msg.size(); i++)
			msg[i] = std::toupper(msg[i]);
	}
	std::cout << msg << std::endl;
	return 0;
}
