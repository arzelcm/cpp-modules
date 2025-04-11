#pragma once
#include "Animal/Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &cat);
	void makeSound() const;
	Cat &operator=(const Cat &cat);
	~Cat();
};