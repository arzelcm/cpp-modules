#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Addresses --> "
			  << "str: " << &str
			  << ", pointer: " << &stringPTR
			  << ", reference: " << &stringREF
			  << std::endl;
	
	std::cout << "Values --> "
			  << "str: " << str
			  << ", pointer: " << stringPTR
			  << ", reference: " << stringREF
			  << std::endl;
	return (0);
}