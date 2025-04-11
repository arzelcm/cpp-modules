#pragma once
#include "Animal/Animal.hpp"
#include "Animal/Brain/Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &cat);
	void makeSound() const;
	Cat &operator=(const Cat &cat);
	~Cat();
};