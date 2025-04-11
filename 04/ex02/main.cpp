#include <iostream>
#include "Animal/Animal.hpp"
#include "Animal/Cat/Cat.hpp"
#include "Animal/Dog/Dog.hpp"

int main(void)
{
	{
		std::cout << "ABSTRACT CLASS TEST" << std::endl;
		Animal *animal = new Dog();
		// Animal *animal = new Animal();
		delete animal;
	}
	std::cout << std::endl;
	{
		std::cout << "ANIMAL FACTORY TEST" << std::endl;
		int animals_a = 4;
		Animal *animals[animals_a];
		for (int i = 0; i < animals_a; i++)
		{
			if (i < animals_a / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (int i = animals_a - 1; i >= 0; i--)
		{
			const Animal *animal = animals[i];
			delete animal;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "DEEP COPIES TEST" << std::endl;
		const Dog *j = new Dog();
		const Animal *i = new Dog(*j);
		delete j; // should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "SUBJECT TEST" << std::endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	return 0;
}