#pragma once
#include "WrongAnimal/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &cat);
	void makeSound() const;
	WrongCat &operator=(const WrongCat &cat);
	~WrongCat();
};