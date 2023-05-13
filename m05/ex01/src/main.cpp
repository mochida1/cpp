/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:56:58 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/12 22:11:34 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cassert>

int test_constructors(void)
{
	std::cout << "\n---------------CONSTRUCTORS----------------" << std::endl;
	std::cout << "\nMain : creating [def] at stack\t\t(default constructor)" << std::endl;
	Bureaucrat def;
	assert (def.getName().compare("default") == 0);
	assert (def.getGrade() == 150 );

	std::cout << "\nMain : creating [argus] at stack\t\t(argument constructor)" << std::endl;
	Bureaucrat argus("Argus" , 15);
	assert (argus.getName().compare("Argus") == 0);
	assert (argus.getGrade() == 15);

	std::cout << "\nMain : copying FROM [argus] TO [def]" << std::endl;
	def = argus;
	assert (def.getName().compare("Argus") != 0); // we can't change a bureaucrat's name for it's constant;
	assert (def.getName().compare("default") == 0);
	assert (def.getGrade() == 15);
	assert (&def != &argus);

	std::cout << "\nMain : creating [copycon](argus) at stack\t\t(copy constructor)" << std::endl;
	Bureaucrat copycon(argus);
	assert (copycon.getName().compare("Argus") == 0); // this works because we've had not yet instantiated copycon;
	assert (copycon.getName().compare("default") != 0);
	assert (copycon.getGrade() == 15);
	assert (&copycon != &argus);


	std::cout << "\n--------- Testing redirection overloads --------" << std::endl;
	std::cout << "def is:\t\t[" << def << "]" << std::endl;
	std::cout << "argus is:\t[" << argus << "]" << std::endl;
	std::cout << "copycon is:\t[" << copycon << "]" << std::endl;

	std::cout << "\n---------CHECKING INSTANCE ADDRESSES--------" << std::endl;
	std::cout << "def address:\t\t" << &def << std::endl;
	std::cout << "argus address:\t\t" << &argus << std::endl;
	std::cout << "copycon address:\t" << &copycon << std::endl;

	return (0);
}

int test_getters(void)
{
	std::cout << "\n---------------GETTERS----------------" << std::endl;
	Bureaucrat def;
	std::cout << "\n" << def << "def.getGrade: "<< def.getGrade() << " should be 150" << std::endl;
	assert (def.getGrade() == 150);
	std::cout << "def.getName: "<< def.getName() << " should be 'default'" << std::endl;
	assert (def.getName().compare("default") == 0);

	Bureaucrat argInit("Argument_initialized", 42);
	std::cout << "\n" << argInit << "argInit.getGrade: "<< argInit.getGrade() << " should be 42" << std::endl;
	assert (argInit.getGrade() == 42);
	std::cout << "argInitf.getName: "<< argInit.getName() << " should be 'Argument_initialized'" << std::endl;
	assert (argInit.getName().compare("Argument_initialized") == 0);

	return 0;
}

int test_setters(void)
{
	std::cout << "\n---------------SETTERS----------------" << std::endl;
	Bureaucrat john("John", 37);

	std::cout << "\nTesting setters for " << john << std::endl;

	std::cout << "Asserting initialization" << std::endl;
	assert (john.getName().compare("John") == 0);
	assert (john.getGrade() == 37);

	std::cout << "Changing John's grade for 1" << std::endl;
	john.setGrade(1);
	std::cout << john << std::endl;
	assert(john.getGrade() == 1);

	std::cout << "Changing John's grade for 150" << std::endl;
	john.setGrade(150);
	std::cout << john << std::endl;
	assert(john.getGrade() == 150);

	std::cout << "Iterating John's grade from 1 to 150" << std::endl;
	for (int i=1; i < 150 ; i++)
	{
		john.setGrade(i);
		assert(john.getGrade() == i);
	}
	std::cout << "Finished iterating john's grade successfully" << std::endl;

	return 0;
}

int test_grades(void)
{
	std::cout << "\n---------------GRADE MODIFIERS----------------" << std::endl;
	Bureaucrat brad("Brad" , 150);
	std::cout << brad << std::endl;
	brad.increaseGrade(149);
	assert (brad.getGrade() == 1);

	brad.decreaseGrade(149);
	assert (brad.getGrade() == 150);

	brad.increaseGrade(50);
	assert (brad.getGrade() == 100);

	brad.increaseGrade(50);
	assert (brad.getGrade() == 50);

	brad.decreaseGrade(25);
	assert (brad.getGrade() == 75);

	brad.decreaseGrade(25);
	assert (brad.getGrade() == 100);

	brad.increaseGrade();
	assert (brad.getGrade() == 99);

	brad.decreaseGrade();
	assert (brad.getGrade() == 100);

	return 0;
}

/*
	ATTENTION THIS WILL INEVITABLY CRASH THE PROGRAM!
*/
int test_exceptions(void)
{
	std::cout << "---------------EXCEPTIONS----------------" << std::endl;

	std::cout << "should throw GRADE TOO LOW" << std::endl;
	Bureaucrat mixerror("minERROR", 151);

	std::cout << "should throw GRADE TOO HIGH" << std::endl;
	Bureaucrat maxerror("maxERROR", 0);

	return 0;
}

int main (int argc, char *argv[])
{
	std::string argument;
	std::string lError("Error, please use one of the following arguments: constructors | getters | setters | grades | ALL | exceptions");
	if (argc > 2)
	{
		std::cerr << lError << std::endl;
		return 1;
	}
	if (argc == 1)
	{
		test_constructors();
		return 0;
	}
	argument = argv[1];
	if (argument.compare("constuctors") == 0)
	{
		test_constructors();
		return 0;
	}
	else if (argument.compare("getters") == 0)
	{
		test_getters();
		return 0;
	}
	else if (argument.compare("setters") == 0)
	{
		test_setters();
		return 0;
	}
	else if (argument.compare("grades") == 0)
	{
		test_grades();
		return 0;
	}
	else if (argument.compare("exceptions") == 0)
	{
		test_exceptions();
		return 0;
	}
	else if (argument.compare("ALL") == 0)
	{
		std::cout << "!!!!!!!!!!!!!!TESTING ALL THE THINGS!!!!!!!!!!!!!!11" << std::endl;
		std::cout << ".. except exceptions..." << std::endl;
		test_constructors();
		test_getters();
		test_setters();
		test_grades();
		return 0;
	}
	std::cerr << lError << std::endl;
	return 0;
}
