/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:18 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/09 19:45:08 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test_constructors(void)
{
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
	std::cout << "\t\t------TESTING [SOUNDS]-------" << std::endl;
	// Animal	ani1;
	Cat		cat1;
	Dog		dog1;
	// std::cout << "ani1.makeSound(): " << std::endl;
	// ani1.makeSound();
	std::cout << "cat1.makeSounds(): " << std::endl;
	cat1.makeSound();
	std::cout << "dog1.makeSounds(): " << std::endl;
	dog1.makeSound();
	return ;
}

void test_subj_ex00(void)
{
	std::cout << "\t\t------TESTING [Ex00 example]-------" << std::endl;
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();

	// delete meta;
	delete j;
	delete i;
}

void test_wrong(void)
{
	std::cout << "\t\t------TESTING [WRONG CLASSES]-------" << std::endl;
	Animal 		*chad = new Cat;
	// WrongAnimal	*simp = new Cat;
	WrongAnimal	*simp = new WrongCat;

	std::cout << "Chad cat: " << std::endl;
	chad->makeSound();
	std::cout << "Simp cat: " << std::endl;
	simp->makeSound();

	delete chad;
	delete simp;

	return ;
}

void brain_constructors(void)
{
	std::cout << "\t\t------TESTING BRAIN INITIALIZATIONS-------" << std::endl;

	Brain def;
	Brain serial("Serial ");
	Brain copy(serial);
	Brain opCon;

	opCon = copy;

	std::cout << "\tPRINTING DEF IDEIAS ---------" << std::endl;
	def.printIdeas();

	std::cout << "\tPRINTING SERIAL IDEIAS ---------" << std::endl;
	serial.printIdeas();

	std::cout << "\tPRINTING COPY IDEIAS ---------" << std::endl;
	copy.printIdeas();

	std::cout << "\tPRINTING OPCON IDEIAS ---------" << std::endl;
	opCon.printIdeas();

	return ;
}

void cat_brain(void)
{
	std::cout << "\tCat with no ideas---------" << std::endl;
	Cat garfield;
	garfield.getBrain()->printIdeas();
}

void dog_brain(void)
{
	std::cout << "\tDog with no ideas---------" << std::endl;
	Dog odie;
	odie.getBrain()->printIdeas();
}

void cat_brain_transplant(void)
{
	std::cout << "\tCat brain transplant: serial ideas---------" << std::endl;
	Cat garfield("Garfield");
	Brain *serial = new Brain("serializedBrain ");
	std::cout << "\tPrinting Garfield's original brain ideas:" << std::endl;
	garfield.getBrain()->printIdeas();
	std::cout << "\tDONE!" <<std::endl;
	std::cout << "\tPrinting Garfield's new brain ideas:" << std::endl;
	garfield.setBrain(serial);
	garfield.getBrain()->printIdeas();
	std::cout << "\tDONE!" <<std::endl;
}
void dog_brain_transplant(void)
{
	std::cout << "\tDog brain transplant: serial ideas---------" << std::endl;
	Dog odie("Odie");
	Brain *serial = new Brain("no thoughts ");
	std::cout << "\tPrinting odie's original brain ideas:" << std::endl;
	odie.getBrain()->printIdeas();
	std::cout << "\tDONE!" <<std::endl;
	std::cout << "\tPrinting odie's new brain ideas:" << std::endl;
	odie.setBrain(serial);
	odie.getBrain()->printIdeas();
	std::cout << "\tDONE!" <<std::endl;
}

void test_brain(void)
{
	brain_constructors();
	cat_brain();
	dog_brain();
	cat_brain_transplant();
	dog_brain_transplant();
}

void test_subj_ex01()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
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
	if (!argument.compare("ex00"))
	{
		std::cout << "Running subject ex00 example ..." << std::endl;
		test_subj_ex00();
		return 0;
	}
	if (!argument.compare("wrong"))
	{
		std::cout << "Running test suite [WRONG] ..." << std::endl;
		test_wrong();
		return 0;
	}
	if (!argument.compare("brain"))
	{
		std::cout << "Running test suite [brain] ..." << std::endl;
		test_brain();
		return 0;
	}
	if (!argument.compare("ex01"))
	{
		std::cout << "Runnning subject ex01 example..." << std::endl;
		test_subj_ex01();
		return 0;
	}

	std::cerr << "Please add a valid input!" << std::endl;
	return 0;
}
