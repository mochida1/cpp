/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:18 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 21:14:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test_constructors(void)
{
	Animal burrito;
	Animal cow("cow");
	Animal calf(cow);
	burrito = cow;
	std::cout << "cow type is: " + cow.getType() << std::endl;
	std::cout << "calf type is: " + calf.getType() << std::endl;
	std::cout << "burrito type is: " + burrito.getType() << std::endl;

	Cat isCat;
	Cat isCow("cow");
	Cat catCopies(isCat);
	Cat catEquals;
	catEquals = isCow;

	std::cout << "isCat is:" + isCat.getType() << std::endl;
	std::cout << "isCow is:" + isCow.getType() << std::endl;
	std::cout << "catCopies is:" + catCopies.getType() << std::endl;
	std::cout << "catEquals is:" + catEquals.getType() << std::endl;

	Dog isDog;
	Dog isNotCat("cow");
	Dog dogCopies(isDog);
	Dog dogEquals;
	dogEquals = isNotCat;

	std::cout << "isDog is:" + isDog.getType() << std::endl;
	std::cout << "isNotCat is:" + isNotCat.getType() << std::endl;
	std::cout << "dogCopies is:" + dogCopies.getType() << std::endl;
	std::cout << "dogEquals is:" + dogEquals.getType() << std::endl;
	return ;
}

void test_sounds(void)
{
	Animal	ani1;
	Cat		cat1;
	Dog		dog1;
	std::cout << "ani1.makeSound(): " << std::endl;
	ani1.makeSound();
	std::cout << "cat1.makeSounds(): " << std::endl;
	cat1.makeSound();
	std::cout << "dog1.makeSounds(): " << std::endl;
	dog1.makeSound();
	return ;
}

void test_subj(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
}

void test_wrong(void)
{
	Animal 		*chad = new Cat;
	// WrongAnimal	*simp = new Cat;
	WrongAnimal	*simp = new WrongCat;

	std::cout << "Chad cat: " << std::endl;
	chad->makeSound();
	std::cout << "Simp cat: " << std::endl;
	simp->makeSound();
	return ;
}

int main(int argc, char *argv[])
{
	std::string argument;
	if (argc > 2)
	{
		std::cerr << "to many arguments" << std::endl;
		return argc;
	}
	if (argc == 1)
	{
		test_constructors();
		return 0;
	}
	argument = argv[1];
	if (!argument.compare("sound"))
	{
		std::cout << "Running test suite [SOUND]...." << std::endl;
		test_sounds();
		return 0;
	}
	if (!argument.compare("subject"))
	{
		std::cout << "Running subject example ..." << std::endl;
		test_subj();
		return 0;
	}
	if (!argument.compare("wrong"))
	{
		std::cout << "Running test suite [WRONG] ..." << std::endl;
		test_wrong();
		return 0;
	}

	std::cerr << "Please add a valid input!" << std::endl;
	return 0;
}
