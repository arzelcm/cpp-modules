#include <iostream>

int main(int argc, char *argv[])
{
	std::string message;

	for (int i = 1; i < argc; i++)
	{
		const std::string str = argv[i];
		for (std::string::size_type j = 0; j < str.size(); j++)
			message.push_back(toupper(str.at(j)));
	}
	if (message.empty())
		message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << message << std::endl;
	return 0;
}
