#pragma once
#include "Animal/Animal.hpp"
#include "Animal/Brain/Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;

public:
	Dog();
	Dog(const Dog &);
	void makeSound() const;
	Dog &operator=(const Dog &);
	~Dog();
};