/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:56:58 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/20 17:34:39 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE
# define VERBOSE 0
#endif //VERBOSE

#define EX01_TESTS

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cassert>
#include <ctime>

void print_timestamp()
{
	std::time_t currentTime = std::time(NULL);
	std::string timeString = std::ctime(&currentTime);
	std::cout << timeString << std::endl;
}

#ifdef EX01_TESTS
void ex01_test_constructors_bureaucrat(void)
{
	std::cout << "\n---------------BUREAUCRATS----------------" << std::endl;
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
}

void ex01_test_constructors_form(void)
{
	std::cout << "\n---------------FORMS----------------" << std::endl;
	std::cout << "\nMain : creating [def] at stack\t\t(default constructor)" << std::endl;
	Form def;
	assert (def.getName().compare("defForm") == 0);
	assert (def.getIsSigned() == false);
	assert (def.getGradeRequiredToSign() == 150 );
	assert (def.getGradeRequiredToExecute() == 150 );
	assert (def.getTarget().compare("") == 0);

	std::cout << "\nMain : creating [argus] at stack\t\t(argument constructor 1)" << std::endl;
	Form argus1("Argus1" , 15, 30);
	assert (argus1.getName().compare("Argus1") == 0);
	assert (argus1.getIsSigned() == false);
	assert (argus1.getGradeRequiredToSign() == 15 );
	assert (argus1.getGradeRequiredToExecute() == 30 );
	assert (def.getTarget().compare("") == 0);

	std::cout << "\nMain : creating [argus] at stack\t\t(argument constructor 2)" << std::endl;
	Form argus2("Argus2" , true, 24, 48);
	assert (argus2.getName().compare("Argus2") == 0);
	assert (argus2.getIsSigned() == true);
	assert (argus2.getGradeRequiredToSign() == 24 );
	assert (argus2.getGradeRequiredToExecute() == 48 );

	std::cout << "\nMain : copying FROM [argus] TO [def]" << std::endl;
	def = argus2;
	assert (def.getName().compare("Argus2") != 0); // we can't change a Form's name for it's constant;
	assert (def.getName().compare("defForm") == 0);
	assert (def.getGradeRequiredToSign() == 150); // can't be changed!
	assert (def.getGradeRequiredToSign() != argus2.getGradeRequiredToSign());
	assert (def.getGradeRequiredToExecute() == 150); // can't be changed!
	assert (def.getGradeRequiredToExecute() != argus2.getGradeRequiredToExecute());
	assert (&def != &argus2);

	std::cout << "\nMain : creating [copycon](argus) at stack\t\t(copy constructor)" << std::endl;
	Form copycon(argus1);
	assert (copycon.getName().compare("Argus1") == 0); // this works because we've had not yet instantiated copycon;
	assert (copycon.getName().compare("defForm") != 0);
	assert (copycon.getGradeRequiredToSign() == argus1.getGradeRequiredToSign());
	assert (copycon.getGradeRequiredToSign() != 150);
	assert (copycon.getGradeRequiredToExecute() == argus1.getGradeRequiredToExecute());
	assert (copycon.getGradeRequiredToExecute() != 150);
	assert (&copycon != &argus1);


	std::cout << "\n--------- Testing redirection overloads --------" << std::endl;
	std::cout << "def is:\t\t[" << def << "]" << std::endl;
	std::cout << "argus1 is:\t[" << argus1 << "]" << std::endl;
	std::cout << "argus2 is:\t[" << argus2 << "]" << std::endl;
	std::cout << "copycon is:\t[" << copycon << "]" << std::endl;

	std::cout << "\n---------CHECKING INSTANCE ADDRESSES--------" << std::endl;
	std::cout << "def address:\t\t" << &def << std::endl;
	std::cout << "argus1 address:\t\t" << &argus1 << std::endl;
	std::cout << "argus2 address:\t\t" << &argus2 << std::endl;
	std::cout << "copycon address:\t" << &copycon << std::endl;
}

int ex01_test_constructors(void)
{
	std::cout << "\n################## CONSTRUCTORS ##################" << std::endl;
	ex01_test_constructors_bureaucrat();
	ex01_test_constructors_form();

	return (0);
}

void ex01_test_getters_bureacrat(void)
{
	std::cout << "\n\n---------------BUREAUCRATS----------------" << std::endl;

	Bureaucrat def;
	std::cout << "\n" << def << "def.getGrade: "<< def.getGrade() << " should be 150" << std::endl;
	assert (def.getGrade() == 150);
	std::cout << "def.getName: "<< def.getName() << " should be 'default'" << std::endl;
	assert (def.getName().compare("default") == 0);

	Bureaucrat argInit("Argument_initialized", 42);
	std::cout << "\n" << argInit << "argInit.getGrade: "<< argInit.getGrade() << " should be 42" << std::endl;
	assert (argInit.getGrade() == 42);
	std::cout << "argInit.getName: "<< argInit.getName() << " should be 'Argument_initialized'" << std::endl;
	assert (argInit.getName().compare("Argument_initialized") == 0);
}

void ex01_test_getters_forms(void)
{
	std::cout << "\n---------------FORMS----------------" << std::endl;

	Form def;
	std::cout << "\n" << def << "def.getGradeRequiredToSign: "<< def.getGradeRequiredToSign() << " should be 150" << std::endl;
	assert (def.getGradeRequiredToSign() == 150);
	std::cout << "\n" << def << "def.getGradeRequiredToExecute: "<< def.getGradeRequiredToExecute() << " should be 150" << std::endl;
	assert (def.getGradeRequiredToExecute() == 150);
	std::cout << "def.getName: "<< def.getName() << " should be 'defForm'" << std::endl;
	assert (def.getName().compare("defForm") == 0);
	std::cout << "def.getIsSigned: ["<< def.getIsSigned() << "] should be [0]" << std::endl;
	assert (def.getIsSigned() == 0);

	Form argInit("Argument_initialized", true, 42, 84);
	std::cout << "\n" << argInit << "argInit.getGradeRequiredToSign: "<< argInit.getGradeRequiredToSign() << " should be 150" << std::endl;
	assert (argInit.getGradeRequiredToSign() == 42);
	std::cout << "\n" << argInit << "argInit.getGradeRequiredToExecute: "<< argInit.getGradeRequiredToExecute() << " should be 150" << std::endl;
	assert (argInit.getGradeRequiredToExecute() == 84);
	std::cout << "argInitf.getName: "<< argInit.getName() << " should be 'Argument_initialized'" << std::endl;
	assert (argInit.getName().compare("Argument_initialized") == 0);
	std::cout << "argInit.getIsSigned: ["<< argInit.getIsSigned() << "] should be [1]" << std::endl;
	assert (argInit.getIsSigned() == 1);
	std::cout << "argInit.getTarget: " << argInit.getTarget() << "shout be ''" << std::endl;
	assert (argInit.getTarget().compare("") == 0);
}

int ex01_test_getters(void)
{
	std::cout << "\n################## GETTERS ##################" << std::endl;
	ex01_test_getters_bureacrat();
	ex01_test_getters_forms();
	return 0;
}

void ex01_test_setters_bureaucrats(void)
{
	std::cout << "\n\n---------------BUREAUCRATS----------------" << std::endl;

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
}

void ex01_test_setters_forms(void)
{
	std::cout << "\n---------------FORMS----------------" << std::endl;

	Form setForm("setForm" , true, 1, 1);
	std::cout << "\nTesting setters for " << setForm << std::endl;
	setForm.setIsSigned(false);
	assert (setForm.getIsSigned() == false);
	setForm.setIsSigned(true);
	assert (setForm.getIsSigned() == true);
	setForm.setIsSigned();
	assert (setForm.getIsSigned() == false);
	setForm.setIsSigned();
	assert (setForm.getIsSigned() == true);
	// testing return values
	assert (setForm.setIsSigned(false) == false);
	assert (setForm.setIsSigned(false) == false);
	assert (setForm.setIsSigned(true) == true);
	assert (setForm.setIsSigned(true) == true);
	assert (setForm.setIsSigned() == false);
	assert (setForm.setIsSigned() == true);

	//ex02
	assert (setForm.getTarget().compare("") == 0);
	assert (setForm.setTarget("custom_target") == true);
	assert (setForm.getTarget().compare("custom_target") == 0);

}

int ex01_test_setters(void)
{
	std::cout << "\n################## SETTERS ##################" << std::endl;

	ex01_test_setters_bureaucrats();
	ex01_test_setters_forms();

	return 0;
}

int ex01_test_grades(void)
{
	std::cout << "\n################## GRADE MODIFIERS ##################" << std::endl;
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
	ATTENTION THESE WILL INEVITABLY CRASH THE PROGRAM!**************************
*/
#define TEST_EXCEPTION_ERROR 0 //change this to make it go poopoo

void ex01_test_exceptions_bureaucrats(void){
	std::cout << "\n\n---------------BUREAUCRATS----------------" << std::endl;

	if (TEST_EXCEPTION_ERROR == 1)
	{
		std::cout << "should throw GRADE TOO LOW" << std::endl;
		Bureaucrat minerror("minERROR", 151);
	}
	else if (TEST_EXCEPTION_ERROR == 2)
	{
		std::cout << "should throw GRADE TOO HIGH" << std::endl;
		Bureaucrat maxerror("maxERROR", 0);
	}
}

void ex01_test_exceptions_forms(void){
	std::cout << "\n---------------FORMS----------------" << std::endl;

	if (TEST_EXCEPTION_ERROR == 3)
	{
		std::cout << "should throw GRADE TOO LOW" << std::endl;
		Form minErrorSign("min error", 151, 25);
	}
	else if (TEST_EXCEPTION_ERROR == 4)
	{
		std::cout << "should throw GRADE TOO LOW" << std::endl;
		Form minErrorExe("min error", 21, 151);
	}
	else if (TEST_EXCEPTION_ERROR == 5)
	{
		std::cout << "should throw GRADE TOO HIGH" << std::endl;
		Form maxErrorSign("max error", 0, 1);
	}
	else if (TEST_EXCEPTION_ERROR == 6)
	{
		std::cout << "should throw GRADE TOO HIGH" << std::endl;
		Form maxErrorExe("max error", 1, 0);
	}
}

int ex01_test_exceptions(void)
{
	std::cout << "################## EXCEPTIONS ##################" << std::endl;
	if (TEST_EXCEPTION_ERROR == 0)
	{
		std::cout << "skipping exceptions...." << std::endl;
		return 0;
	}
	ex01_test_exceptions_bureaucrats();
	ex01_test_exceptions_forms();

	return 0;
}
/*
	****************************************************************************
*/

void ex01_test_be_signed(void)
{
	std::cout << "################## BE SIGNED ##################" << std::endl;

	Bureaucrat	def;
	Bureaucrat	limit("Limit", 42);
	Bureaucrat	chad("Chad", 1);
	Form		test("testForm", false, 42, 20);

	assert (test.getIsSigned() == false);
	std::cout << "[01]" << test << " being signed by " << def << "should fail!" << std::endl;
	assert (test.beSigned(def) == false);
	test.setIsSigned(true);
	assert(test.getIsSigned() == true);
	std::cout << "[02]" << test << " being signed by " << def << "should fail!" << std::endl;
	assert (test.beSigned(def) == false);

	test.setIsSigned(false);
	assert (test.getIsSigned() == false);
	std::cout << "[03]" << test << " being signed by " << limit << "should succeed!" << std::endl;
	assert (test.beSigned(limit) == true);
	assert(test.getIsSigned() == true);
	std::cout << "[05]" << test << " being signed by " << limit << "should not succeed!" << std::endl;
	assert (test.beSigned(limit) == false);

	test.setIsSigned(false);
	assert (test.getIsSigned() == false);
	std::cout << "[06]" << test << " being signed by " << chad << "should succeed!" << std::endl;
	assert (test.beSigned(chad) == true);
	assert(test.getIsSigned() == true);
	std::cout << "[07]" << test << " being signed by " << chad << "should not succeed!" << std::endl;
	assert (test.beSigned(chad) == false);

	std::cout << "\tAll 'be_signed' tests sucessful!-------" << std::endl;
	return ;
}

void ex01_test_sign(void)
{
	std::cout << "################## SIGN ##################" << std::endl;

	Bureaucrat	def;
	Bureaucrat	limit("Limit", 42);
	Bureaucrat	chad("Chad", 1);
	Form		test("testForm", false, 42, 20);

	assert (test.getIsSigned() == false);
	std::cout << "[01]" << test << " being signed by " << def << "should fail!" << std::endl;
	assert (def.signForm(test) == false);
	test.setIsSigned(true);
	assert(test.getIsSigned() == true);
	std::cout << "[02]" << test << " being signed by " << def << "should fail!" << std::endl;
	assert (def.signForm(test) == false);

	test.setIsSigned(false);
	assert (test.getIsSigned() == false);
	std::cout << "[03]" << test << " being signed by " << limit << "should succeed!" << std::endl;
	assert (limit.signForm(test) == true);
	assert(test.getIsSigned() == true);
	std::cout << "[05]" << test << " being signed by " << limit << "should not succeed!" << std::endl;
	assert (limit.signForm(test) == false);

	test.setIsSigned(false);
	assert (test.getIsSigned() == false);
	std::cout << "[06]" << test << " being signed by " << chad << "should succeed!" << std::endl;
	assert (chad.signForm(test) == true);
	assert(test.getIsSigned() == true);
	std::cout << "[07]" << test << " being signed by " << chad << "should not succeed!" << std::endl;
	assert (chad.signForm(test) == false);

	std::cout << "\tAll 'sign' tests sucessful!-------" << std::endl;
	return ;
}
#endif // EX01_TESTS

void test_ex01(void)
{
	#ifndef EX01_TESTS
	std::cout << "Warning: Not testing ex01." << std::endl;
	#endif // !EX01_TESTS
	#ifdef EX01_TESTS
	std::cout << "!!!!!!!!!!!!!!TESTING EX01 THINGS!!!!!!!!!!!!!!11" << std::endl;
	std::cout << ".. except exceptions..." << std::endl;

	ex01_test_constructors();
	ex01_test_getters();
	ex01_test_setters();
	ex01_test_grades();
	ex01_test_be_signed();
	ex01_test_sign();
	ex01_test_exceptions();

	std::cout << "\n" << std::endl;
	print_timestamp();
	std::cout << "ALL TESTS COMPLETED SUCCESSFULLY!" << std::endl;
	#endif // EX01_TESTS
}



void ex02_test_constructors(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 CONSTRUCTORS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm def;
	assert (def.getIsSigned() == false);
	assert (def.getName().compare("PresidentialPardonForm") == 0);
	assert (def.getTarget().compare("") == 0);
	assert (def.getGradeRequiredToSign() == 25);
	assert (def.getGradeRequiredToExecute() == 5);
	if (VERBOSE)
		std::cout << def << std::endl;

	PresidentialPardonForm argument("argument_target");
	assert (argument.getName().compare("PresidentialPardonForm") == 0);
	assert (argument.getTarget().compare("argument_target") == 0);
	assert (argument.getIsSigned() == false);
	assert (argument.getGradeRequiredToSign() == 25);
	assert (argument.getGradeRequiredToExecute() == 5);
	if (VERBOSE)
		std::cout << argument << std::endl;

	def.setIsSigned(true);
	assert (def.getIsSigned() == true);
	def = argument;
	assert (def.getIsSigned() == false);
	assert (def.getName().compare("PresidentialPardonForm") == 0);
	assert (def.getTarget().compare("argument_target") == 0);
	assert (def.getGradeRequiredToSign() == 25);
	assert (def.getGradeRequiredToExecute() == 5);
	if (VERBOSE)
		std::cout << def << std::endl;

	argument.setTarget("copycon_target");
	assert (argument.getTarget().compare("copycon_target") == 0);
	PresidentialPardonForm copycon(argument);
	assert (copycon.getName().compare("PresidentialPardonForm") == 0);
	assert (copycon.getTarget().compare("copycon_target") == 0);
	assert (copycon.getIsSigned() == false);
	assert (copycon.getGradeRequiredToSign() == 25);
	assert (copycon.getGradeRequiredToExecute() == 5);
	if (VERBOSE)
		std::cout << copycon << std::endl;
}

void ex02_test_getters(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 GETTERS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("**TARGET**");
	assert (ppf.getTarget().compare("**TARGET**") == 0);
	assert (ppf.getName().compare("PresidentialPardonForm") == 0);
	assert (ppf.getIsSigned() == false);
	assert (ppf.getGradeRequiredToSign() == 25);
	assert (ppf.getGradeRequiredToExecute() == 5);
}

void ex02_test_setters(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 SETTERS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("start_target");
	assert (ppf.setIsSigned(true) == true);
	assert (ppf.getIsSigned() == true);
	assert (ppf.setIsSigned(false) == false);
	assert (ppf.getIsSigned() == false);
	assert (ppf.getTarget().compare("start_target") == 0);
	ppf.setTarget("end_target");
	assert (ppf.getTarget().compare("end_target") == 0);
}

void ex02_test_grades(void)
{
	return ;
}

void ex02_test_exceptions(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 EXCEPTIONS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("..target..");
	Bureaucrat chad("chad", 1);

	// ppf.execute(chad);

}

void ex02_test_be_signed(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 beSigned() $$$$$$$$$$$$$" << std::endl;
	PresidentialPardonForm ppf("ppf_target");
	Bureaucrat chad("chad", 1);
	Bureaucrat failer("failer", 150);

	assert (ppf.getIsSigned() == false);
	assert (ppf.beSigned(chad) == true);
	assert (ppf.getIsSigned() == true);
	assert (ppf.beSigned(chad) == false);
	assert (ppf.getIsSigned() == true);


	assert (ppf.setIsSigned(false) == false);
	assert (ppf.beSigned(failer) == false);
	assert (ppf.setIsSigned(true) == true);
	assert (ppf.getIsSigned() == true);
	assert (ppf.beSigned(failer) == false);

}

void ex02_test_sign(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 signForm() $$$$$$$$$$$$$" << std::endl;
	PresidentialPardonForm ppf("ppf_target");
	Bureaucrat chad("chad", 1);
	Bureaucrat failer("failer", 150);

	assert (ppf.setIsSigned(false) == false);
	assert (chad.signForm(ppf) == true);
	assert (ppf.getIsSigned() == true);
	assert (chad.signForm(ppf) == false);
	assert (ppf.getIsSigned() == true);

	assert (ppf.setIsSigned(true) == true);
	assert (failer.signForm(ppf) == false);
	assert (ppf.getIsSigned() == true);
	assert (ppf.setIsSigned() == false);
	assert (ppf.getIsSigned() == false);
	assert (failer.signForm(ppf) == false);
	assert (ppf.getIsSigned() == false);
}

void ex02_execute(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 execute() $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("target");
	RobotomyRequestForm rrf("bill");
	Bureaucrat chad("chad", 5);
	Bureaucrat failer("failer", 150);

//	ppf.execute(chad);
//	ppf.execute(failer);

	chad.signForm(ppf);
	ppf.execute(chad);

	chad.signForm(rrf);
	rrf.execute(chad);
}

void ex02_executeForm(void)
{
	std::cout << "$$$$$$$$$$$$$ TESTING EX02 executeForm() $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("A really generic target");
	Bureaucrat chad("chad", 5);
	Bureaucrat failer("failer", 150);

	chad.signForm(ppf);
	chad.executeForm(ppf);
}

int main (int argc, char *argv[])
{
	std::string argument;
	std::string lError("Error, please use one of the following arguments: ex01 | constructors | getters | setters | grades | be_signed | sign | execute | execute_form | ALL | exceptions");
	if (argc > 2)
	{
		std::cerr << lError << std::endl;
		return 1;
	}
	if (argc == 1)
	{
		ex02_test_constructors();
		return 0;
	}
	argument = argv[1];
	if (argument.compare("ex01") == 0)
	{
		#ifdef EX01_TESTS
		test_ex01();
		#endif
		return 0;
	}
	if (argument.compare("constuctors") == 0)
	{
		ex02_test_constructors();
		return 0;
	}
	else if (argument.compare("getters") == 0)
	{
		ex02_test_getters();
		return 0;
	}
	else if (argument.compare("setters") == 0)
	{
		ex02_test_setters();
		return 0;
	}
	else if (argument.compare("grades") == 0)
	{
		ex02_test_grades();
		return 0;
	}
	else if (argument.compare("exceptions") == 0)
	{
		ex02_test_exceptions();
		return 0;
	}
	else if (argument.compare("be_signed") == 0)
	{
		ex02_test_be_signed();
		return 0;
	}
	else if (argument.compare("sign") == 0)
	{
		ex02_test_sign();
		return 0;
	}
	else if (argument.compare("ALL") == 0)
	{


		std::cout << "!!!!!!!!!!!!!!TESTING ALL THE THINGS!!!!!!!!!!!!!!11" << std::endl;
		std::cout << ".. except exceptions... and ex01... " << std::endl;


 		ex02_test_constructors();
 		ex02_test_getters();
 		ex02_test_setters();
 		ex02_test_grades();
 		ex02_test_exceptions();
 		ex02_test_be_signed();
 		ex02_test_sign();
		ex02_execute();
		ex02_executeForm();

		std::cout << "\n" << std::endl;
		print_timestamp();
		std::cout << "ALL TESTS COMPLETED SUCCESSFULLY!" << std::endl;
		return 0;
	}
	std::cerr << lError << std::endl;
	return 0;
}
