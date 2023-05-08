/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:56:58 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/07 20:15:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cassert>
# define VERBOSE 1

int test_constructors(void)
{
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

int test_exceptions(void)
{
	return 0;
}

int main (int argc, char *argv[])
{
	std::string argument;

	if (argc > 2)
	{
		std::cerr << "Error, please use one of the following arguments: constructors | getters | exceptions" << std::endl;
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
	else if (argument.compare("exceptions") == 0)
	{
		test_exceptions();
		return 0;
	}
	std::cerr << "Error, please use one of the following arguments: constructors | exceptions | all" << std::endl;
	return 0;
}
