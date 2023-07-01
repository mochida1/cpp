/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:18 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/30 22:06:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void tests(void)
{
	Base base;
	// std::cout << base.getClassName() << std::endl;
	assert( base.getClassName().compare("Base") == 0 );
	A a;
	std::cout << a.getClassName() << std::endl;
	assert( a.getClassName().compare("Class A") == 0);
	B b;
	// std::cout << b.getClassName() << std::endl;
	assert( b.getClassName().compare("Class is B!") == 0);
	C c;
	// std::cout << c.getClassName() << std::endl;
	assert( c.getClassName().compare("Class is not A nor B. Threfore it's C") == 0);

	Base *basePtr;
	basePtr = new A;
	// std::cout << basePtr->getClassName() << std::endl;
	assert( basePtr->getClassName().compare("Class A") == 0);
	delete basePtr;
	int i = 0;
	int charctl = 0;
	std::cout << "Generating all random classes, please wait..." << std::endl;
	while (i != 0b111)
	{
		basePtr = generate();
		if ( ((i & 0b001) == 0) && basePtr->getClassName().compare("Class A") == 0 )
			i |= 0b001;
		else if ( ((i & 0b010) == 0) && basePtr->getClassName().compare("Class is B!") == 0)
			i |= 0b010;
		else if ( ((i & 0b100) == 0) )
			i |= 0b100;
		delete basePtr;

		if (charctl++ < 3)
		{
			if (i == 0)
				std::cout << ".";
			else if (i == 1)
				std::cout << ":";
			else if (i == 2)
				std::cout << "_";
			else if (i == 3)
				std::cout << "!";
			else if (i == 4)
				std::cout << "|";
			else if (i == 5)
				std::cout << ">";
			else if (i == 6)
				std::cout << "#";
		}
		std::cout.flush();
		usleep(1 * 100 * 100);

		if (charctl >= 4)
		{
			std::cout << "\r";
			charctl = 0;
		}
		std::cout.flush();
	}
	std::cout << "\nAll random classes generated :)" << std::endl;
}

Base * generate(void) {
	int random_number;
	std::srand((unsigned int)time(NULL));

	random_number = rand() % 3;
	if (random_number == 0)
		return (new A);
	else if (random_number == 1)
		return (new B);
	return (new C);
}

void identify(Base* p);
void identify(Base& p);

int main (void)
{
	tests();
}
