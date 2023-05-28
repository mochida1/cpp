/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:56:58 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/28 19:14:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE
# define VERBOSE 0
#endif //VERBOSE

// #define EX01_TESTS

#define	SCF_SIGN	145
#define	SCF_EXEC	137
#define	RRF_SIGN	72
#define	RRF_EXEC	45
#define	PPF_SIGN	25
#define	PPF_EXEC	5


#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cassert>
#include <ctime>
#include <sstream>

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

	brad.decreaseGrade(75);
	assert (brad.getGrade() == 75);

	brad.decreaseGrade(75);
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
		Form minErrorSign("min error", 151, 75);
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
5
	std::cout << "\n" << std::endl;
	print_timestamp();
	std::cout << "ALL TESTS COMPLETED SUCCESSFULLY!" << std::endl;
	#endif // EX01_TESTS
}



void ex02_test_constructors(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 CONSTRUCTORS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm def;
	assert (def.getIsSigned() == false);
	assert (def.getName().compare("PresidentialPardonForm") == 0);
	assert (def.getTarget().compare("") == 0);
	assert (def.getGradeRequiredToSign() == PPF_SIGN);
	assert (def.getGradeRequiredToExecute() == PPF_EXEC);
	if (VERBOSE)
		std::cout << def << std::endl;

	PresidentialPardonForm argument("argument_target");
	assert (argument.getName().compare("PresidentialPardonForm") == 0);
	assert (argument.getTarget().compare("argument_target") == 0);
	assert (argument.getIsSigned() == false);
	assert (argument.getGradeRequiredToSign() == PPF_SIGN);
	assert (argument.getGradeRequiredToExecute() == PPF_EXEC);
	if (VERBOSE)
		std::cout << argument << std::endl;

	def.setIsSigned(true);
	assert (def.getIsSigned() == true);
	def = argument;
	assert (def.getIsSigned() == false);
	assert (def.getName().compare("PresidentialPardonForm") == 0);
	assert (def.getTarget().compare("argument_target") == 0);
	assert (def.getGradeRequiredToSign() == PPF_SIGN);
	assert (def.getGradeRequiredToExecute() == PPF_EXEC);
	if (VERBOSE)
		std::cout << def << std::endl;

	argument.setTarget("copycon_target");
	assert (argument.getTarget().compare("copycon_target") == 0);
	PresidentialPardonForm copycon(argument);
	assert (copycon.getName().compare("PresidentialPardonForm") == 0);
	assert (copycon.getTarget().compare("copycon_target") == 0);
	assert (copycon.getIsSigned() == false);
	assert (copycon.getGradeRequiredToSign() == PPF_SIGN);
	assert (copycon.getGradeRequiredToExecute() == PPF_EXEC);
	if (VERBOSE)
		std::cout << copycon << std::endl;

	// SHRUBBERY
	ShrubberyCreationForm scfDef;
	assert (scfDef.getTarget().compare("") == 0);
	assert (scfDef.getName().compare("ShrubberyCreationForm") == 0);
	assert (scfDef.getGradeRequiredToSign() == SCF_SIGN);
	assert (scfDef.getGradeRequiredToExecute() == SCF_EXEC);
	assert (scfDef.getIsSigned() == false);
	if (VERBOSE)
		std::cout << scfDef << std::endl;

	ShrubberyCreationForm scfArg("scfArg_target");
	assert (scfArg.getTarget().compare("scfArg_target") == 0);
	assert (scfArg.getName().compare("ShrubberyCreationForm") == 0);
	assert (scfArg.getGradeRequiredToSign() == SCF_SIGN);
	assert (scfArg.getGradeRequiredToExecute() == SCF_EXEC);
	assert (scfArg.getIsSigned() == false);
	if (VERBOSE)
		std::cout << scfArg << std::endl;

	scfArg.setTarget("scfCopyConstructor_target");
	assert (scfArg.getTarget().compare("scfCopyConstructor_target") == 0);
	assert (scfArg.setIsSigned(true) == true);
	assert (scfArg.getIsSigned() == true);
	ShrubberyCreationForm scfCopy(scfArg);
	assert (scfCopy.getTarget().compare("scfCopyConstructor_target") == 0);
	assert (scfCopy.getName().compare("ShrubberyCreationForm") == 0);
	assert (scfCopy.getGradeRequiredToSign() == SCF_SIGN);
	assert (scfCopy.getGradeRequiredToExecute() == SCF_EXEC);
	assert (scfCopy.getIsSigned() == true);
	if (VERBOSE)
	{
		std::cout << scfArg << std::endl;
		std::cout << scfCopy << std::endl;
	}

	ShrubberyCreationForm scfCopyOp;
	assert (scfCopyOp.getTarget().compare("") == 0);
	assert (scfCopyOp.getName().compare("ShrubberyCreationForm") == 0);
	assert (scfCopyOp.getGradeRequiredToSign() == SCF_SIGN);
	assert (scfCopyOp.getGradeRequiredToExecute() == SCF_EXEC);
	assert (scfCopyOp.getIsSigned() == false);
	if (VERBOSE)
		std::cout << scfCopyOp << std::endl;
	scfCopyOp = scfArg;
	assert (scfCopyOp.getTarget().compare("scfCopyConstructor_target") == 0);
	assert (scfCopyOp.getName().compare("ShrubberyCreationForm") == 0);
	assert (scfCopyOp.getGradeRequiredToSign() == SCF_SIGN);
	assert (scfCopyOp.getGradeRequiredToExecute() == SCF_EXEC);
	assert (scfCopyOp.getIsSigned() == true);
	if (VERBOSE)
	{
		std::cout << scfArg << std::endl;
		std::cout << scfCopyOp << std::endl;
	}

	// ROBOTOMY
	RobotomyRequestForm rrfDef;
	assert (rrfDef.getTarget().compare("") == 0);
	assert (rrfDef.getName().compare("RobotomyRequestForm") == 0);
	assert (rrfDef.getGradeRequiredToSign() == RRF_SIGN);
	assert (rrfDef.getGradeRequiredToExecute() == RRF_EXEC);
	assert (rrfDef.getIsSigned() == false);
	if (VERBOSE)
		std::cout << rrfDef << std::endl;

	RobotomyRequestForm rrfArg("rrfArg_target");
	assert (rrfArg.getTarget().compare("rrfArg_target") == 0);
	assert (rrfArg.getName().compare("RobotomyRequestForm") == 0);
	assert (rrfArg.getGradeRequiredToSign() == RRF_SIGN);
	assert (rrfArg.getGradeRequiredToExecute() == RRF_EXEC);
	assert (rrfArg.getIsSigned() == false);
	if (VERBOSE)
		std::cout << rrfArg << std::endl;

	rrfArg.setTarget("rrfCopyConstructor_target");
	assert (rrfArg.getTarget().compare("rrfCopyConstructor_target") == 0);
	assert (rrfArg.setIsSigned(true) == true);
	assert (rrfArg.getIsSigned() == true);
	RobotomyRequestForm rrfCopy(rrfArg);
	assert (rrfCopy.getTarget().compare("rrfCopyConstructor_target") == 0);
	assert (rrfCopy.getName().compare("RobotomyRequestForm") == 0);
	assert (rrfCopy.getGradeRequiredToSign() == RRF_SIGN);
	assert (rrfCopy.getGradeRequiredToExecute() == RRF_EXEC);
	assert (rrfCopy.getIsSigned() == true);
	if (VERBOSE)
	{
		std::cout << rrfArg << std::endl;
		std::cout << rrfCopy << std::endl;
	}

	RobotomyRequestForm rrfCopyOp;
	assert (rrfCopyOp.getTarget().compare("") == 0);
	assert (rrfCopyOp.getName().compare("RobotomyRequestForm") == 0);
	assert (rrfCopyOp.getGradeRequiredToSign() == RRF_SIGN);
	assert (rrfCopyOp.getGradeRequiredToExecute() == RRF_EXEC);
	assert (rrfCopyOp.getIsSigned() == false);
	if (VERBOSE)
		std::cout << rrfCopyOp << std::endl;
	rrfCopyOp = rrfArg;
	assert (rrfCopyOp.getTarget().compare("rrfCopyConstructor_target") == 0);
	assert (rrfCopyOp.getName().compare("RobotomyRequestForm") == 0);
	assert (rrfCopyOp.getGradeRequiredToSign() == RRF_SIGN);
	assert (rrfCopyOp.getGradeRequiredToExecute() == RRF_EXEC);
	assert (rrfCopyOp.getIsSigned() == true);
	if (VERBOSE)
	{
		std::cout << rrfArg << std::endl;
		std::cout << rrfCopyOp << std::endl;
	}
}

void ex02_test_getters(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 GETTERS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("**TARGET**");
	assert (ppf.getTarget().compare("**TARGET**") == 0);
	assert (ppf.getName().compare("PresidentialPardonForm") == 0);
	assert (ppf.getIsSigned() == false);
	assert (ppf.getGradeRequiredToSign() == PPF_SIGN);
	assert (ppf.getGradeRequiredToExecute() == PPF_EXEC);

	RobotomyRequestForm rrf("**TARGET**");
	assert (rrf.getTarget().compare("**TARGET**") == 0);
	assert (rrf.getName().compare("RobotomyRequestForm") == 0);
	assert (rrf.getIsSigned() == false);
	assert (rrf.getGradeRequiredToSign() == RRF_SIGN);
	assert (rrf.getGradeRequiredToExecute() == RRF_EXEC);

	ShrubberyCreationForm scf("**TARGET**");
	assert (scf.getTarget().compare("**TARGET**") == 0);
	assert (scf.getName().compare("ShrubberyCreationForm") == 0);
	assert (scf.getIsSigned() == false);
	assert (scf.getGradeRequiredToSign() == SCF_SIGN);
	assert (scf.getGradeRequiredToExecute() == SCF_EXEC);
}

void ex02_test_setters(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 SETTERS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("start_target");
	assert (ppf.setIsSigned(true) == true);
	assert (ppf.getIsSigned() == true);
	assert (ppf.setIsSigned(false) == false);
	assert (ppf.getIsSigned() == false);
	assert (ppf.getTarget().compare("start_target") == 0);
	ppf.setTarget("end_target");
	assert (ppf.getTarget().compare("end_target") == 0);

	RobotomyRequestForm rrf("start_target");
	assert (rrf.setIsSigned(true) == true);
	assert (rrf.getIsSigned() == true);
	assert (rrf.setIsSigned(false) == false);
	assert (rrf.getIsSigned() == false);
	assert (rrf.getTarget().compare("start_target") == 0);
	rrf.setTarget("end_target");
	assert (rrf.getTarget().compare("end_target") == 0);

	ShrubberyCreationForm scf("start_target");
	assert (scf.setIsSigned(true) == true);
	assert (scf.getIsSigned() == true);
	assert (scf.setIsSigned(false) == false);
	assert (scf.getIsSigned() == false);
	assert (scf.getTarget().compare("start_target") == 0);
	scf.setTarget("end_target");
	assert (scf.getTarget().compare("end_target") == 0);
}

void ex02_test_exceptions(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 EXCEPTIONS $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("ppf_target");
	ShrubberyCreationForm scf("scf_target");
	RobotomyRequestForm rrf("rrf_target");
	Bureaucrat chad("chad", 1);
	Bureaucrat failer("failer", 150);

	/* UNSIGNED*/
	// ppf.execute(chad);
	// scf.execute(chad);
	// rrf.execute(chad);


	ppf.setIsSigned(true);
	scf.setIsSigned(true);
	rrf.setIsSigned(true);

	/* GRADE TOO LOW*/
	// ppf.execute(failer);
	// scf.execute(failer);
	// rrf.execute(failer);

}

void ex02_test_be_signed(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 beSigned() $$$$$$$$$$$$$" << std::endl;
	PresidentialPardonForm ppf("ppf_target");
	RobotomyRequestForm rrf("rrf_target");
	ShrubberyCreationForm scf("scf_target");
	Bureaucrat chad("chad", 1);
	Bureaucrat failer("failer", 150);

	/* PRESIDENTIAL PARDON FORM */
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

	/* ROBOTOMY REQUEST FORM*/
	assert (rrf.getIsSigned() == false);
	assert (rrf.beSigned(chad) == true);
	assert (rrf.getIsSigned() == true);
	assert (rrf.beSigned(chad) == false);
	assert (rrf.getIsSigned() == true);

	assert (rrf.setIsSigned(false) == false);
	assert (rrf.beSigned(failer) == false);
	assert (rrf.setIsSigned(true) == true);
	assert (rrf.getIsSigned() == true);
	assert (rrf.beSigned(failer) == false);

	/* SHRUBBERY CREATION FORM*/
	assert (scf.getIsSigned() == false);
	assert (scf.beSigned(chad) == true);
	assert (scf.getIsSigned() == true);
	assert (scf.beSigned(chad) == false);
	assert (scf.getIsSigned() == true);

	assert (scf.setIsSigned(false) == false);
	assert (scf.beSigned(failer) == false);
	assert (scf.setIsSigned(true) == true);
	assert (scf.getIsSigned() == true);
	assert (scf.beSigned(failer) == false);
}

void ex02_test_sign(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 signForm() $$$$$$$$$$$$$" << std::endl;
	PresidentialPardonForm ppf("ppf_target");
	RobotomyRequestForm rrf("rrf_target");
	ShrubberyCreationForm scf("scf_target");
	Bureaucrat chad("chad", 1);
	Bureaucrat failer("failer", 150);

	/* PRESIDENTIAL PARDON FORM */
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

	/* ROBOTOMY REQUEST FORM*/
	assert (rrf.setIsSigned(false) == false);
	assert (chad.signForm(rrf) == true);
	assert (rrf.getIsSigned() == true);
	assert (chad.signForm(rrf) == false);
	assert (rrf.getIsSigned() == true);

	assert (rrf.setIsSigned(true) == true);
	assert (failer.signForm(rrf) == false);
	assert (rrf.getIsSigned() == true);
	assert (rrf.setIsSigned() == false);
	assert (rrf.getIsSigned() == false);
	assert (failer.signForm(rrf) == false);
	assert (rrf.getIsSigned() == false);

	/* SHRUBBERY CREATION FORM*/
	assert (scf.setIsSigned(false) == false);
	assert (chad.signForm(scf) == true);
	assert (scf.getIsSigned() == true);
	assert (chad.signForm(scf) == false);
	assert (scf.getIsSigned() == true);

	assert (scf.setIsSigned(true) == true);
	assert (failer.signForm(scf) == false);
	assert (scf.getIsSigned() == true);
	assert (scf.setIsSigned() == false);
	assert (scf.getIsSigned() == false);
	assert (failer.signForm(scf) == false);
	assert (scf.getIsSigned() == false);

	/* LIMITS */
		// failure
	ppf.setIsSigned(false);
	rrf.setIsSigned(false);
	scf.setIsSigned(false);
	assert (ppf.getIsSigned() == false);
	assert (rrf.getIsSigned() == false);
	assert (scf.getIsSigned() == false);
	failer.setGrade(PPF_SIGN + 1);
	failer.signForm(ppf);
	failer.setGrade(RRF_SIGN + 1);
	failer.signForm(rrf);
	failer.setGrade(SCF_SIGN + 1);
	failer.signForm(scf);
	assert (ppf.getIsSigned() == false);
	assert (rrf.getIsSigned() == false);
	assert (scf.getIsSigned() == false);
		// success
	ppf.setIsSigned(false);
	rrf.setIsSigned(false);
	scf.setIsSigned(false);
	assert (ppf.getIsSigned() == false);
	assert (rrf.getIsSigned() == false);
	assert (scf.getIsSigned() == false);
	chad.setGrade(PPF_SIGN);
	chad.signForm(ppf);
	chad.setGrade(RRF_SIGN);
	chad.signForm(rrf);
	chad.setGrade(SCF_SIGN);
	chad.signForm(scf);
	assert (ppf.getIsSigned() == true);
	assert (rrf.getIsSigned() == true);
	assert (scf.getIsSigned() == true);
}

void ex02_execute(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 execute() $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("target");
	RobotomyRequestForm rrf("bill");
	ShrubberyCreationForm scf("scf_target_ex02_execute");
	Bureaucrat chad("chad", 5);
	Bureaucrat failer("failer", 150);

//	ppf.execute(chad);
//	ppf.execute(failer);

	chad.signForm(ppf);
	chad.signForm(rrf);
	chad.signForm(scf);

	chad.setGrade(PPF_EXEC);
	ppf.execute(chad);
	chad.setGrade(RRF_EXEC);
	rrf.execute(chad);
	chad.setGrade(SCF_EXEC);
	scf.execute(chad);

	chad.setGrade(PPF_EXEC + 1);
	// ppf.execute(chad);
	chad.setGrade(RRF_EXEC + 1);
	// rrf.execute(chad);
	chad.setGrade(SCF_EXEC + 1);
	// scf.execute(chad);
}

void ex02_executeForm(void)
{
	std::cout << "\n$$$$$$$$$$$$$ TESTING EX02 executeForm() $$$$$$$$$$$$$" << std::endl;

	PresidentialPardonForm ppf("A really generic target");
	RobotomyRequestForm rrf("RRF_TARGET");
	ShrubberyCreationForm scf("SCF_TARGET");
	Bureaucrat chad("chad", 5);
	Bureaucrat failer("failer", 150);

	std::cout << "\t\tthese should fail!" << std::endl;
	chad.executeForm(ppf);
	chad.executeForm(rrf);
	chad.executeForm(scf);
	failer.executeForm(ppf);
	failer.executeForm(rrf);
	failer.executeForm(scf);
	std::cout << std::endl;

	ppf.setIsSigned(true);
	rrf.setIsSigned(true);
	scf.setIsSigned(true);

	failer.setGrade(PPF_EXEC + 1);
	failer.executeForm(ppf);
	failer.setGrade(RRF_EXEC + 1);
	failer.executeForm(rrf);
	failer.setGrade(SCF_EXEC + 1);
	failer.executeForm(scf);


	std::cout << "\t\tthese should SUCCEED!" << std::endl;
	chad.setGrade(PPF_EXEC);
	chad.executeForm(ppf);
	chad.setGrade(RRF_EXEC);
	chad.executeForm(rrf);
	chad.setGrade(SCF_EXEC);
	chad.executeForm(scf);

}

void test_ex02(void)
{
	ex02_test_constructors();
	ex02_test_getters();
	ex02_test_setters();
	ex02_test_exceptions();
	ex02_test_be_signed();
	ex02_test_sign();
	ex02_execute();
	ex02_executeForm();
}

void ex03_test_constructors(void)
{
	std::cout << "\n@@@@@@@@@@@@@ TESTING EX03 CONSTRUCTORS @@@@@@@@@@@@@" << std::endl;
	Intern a;
	Intern b;
	b = a;
	assert (&a != &b);
	Intern c(a);
	assert (&a != &c);
}

void	ex03_makeForm(void)
{
	std::cout << "\n@@@@@@@@@@@@@ TESTING EX03 makeForm() @@@@@@@@@@@@@" << std::endl;
	Intern a;
	Form * scf = a.makeForm("shrubbery creation", "scf_target");
	assert (scf != NULL);
	assert (scf->getName().compare("ShrubberyCreationForm") == 0);
	assert (scf->getTarget().compare("scf_target") == 0);
	assert (scf->getIsSigned() == false);
	assert (scf->getGradeRequiredToSign() == SCF_SIGN);
	assert (scf->getGradeRequiredToExecute() == SCF_EXEC);

	Form * rrf = a.makeForm("robotomy request", "rrf_target");
	assert (rrf != NULL);
	assert (rrf->getName().compare("RobotomyRequestForm") == 0);
	assert (rrf->getTarget().compare("rrf_target") == 0);
	assert (rrf->getIsSigned() == false);
	assert (rrf->getGradeRequiredToSign() == RRF_SIGN);
	assert (rrf->getGradeRequiredToExecute() == RRF_EXEC);

	Form * ppf = a.makeForm("presidential pardon", "ppf_target");
	assert (ppf != NULL);
	assert (ppf->getName().compare("PresidentialPardonForm") == 0);
	assert (ppf->getTarget().compare("ppf_target") == 0);
	assert (ppf->getIsSigned() == false);
	assert (ppf->getGradeRequiredToSign() == PPF_SIGN);
	assert (ppf->getGradeRequiredToExecute() == PPF_EXEC);

	Form * wrongForm = a.makeForm("wrong form", "wrong_ form_target");
	assert (wrongForm == NULL);

	delete scf;
	delete rrf;
	delete ppf;
}

#define MAX_CMD_NUMBER 4

void ex03_poc_doCommand(int index, Form *&formTemplate, Bureaucrat *burList);

void	ex03_poc(void)
{
	Bureaucrat	master("Master", PPF_EXEC);
	Bureaucrat	specialist("Specialist", PPF_SIGN);
	Bureaucrat	senior("Senior", RRF_EXEC);
	Bureaucrat	midlvl("Midlvl", RRF_SIGN);
	Bureaucrat	junior("Junior", SCF_EXEC);
	Bureaucrat	trainee("Trainee", SCF_SIGN);
	Bureaucrat	intern("Intern", 150);
	Bureaucrat	burList[7] = { master, specialist, senior, midlvl, junior,trainee, intern };
	Form		*formTemplate = NULL;
	char		errflag = 1;

	std::string command_list[MAX_CMD_NUMBER] = {
		"A",
		"B",
		"C",
		"D"
	};
	std::cout << "Welcome to bureaucracy!" << std::endl;
	std::string command;
	while (1)
	{
		std::cout << "\nPlease chose a command: ";
		std::cout << "\n[A] - Make a form";
		std::cout << "\n[B] - Sign a form";
		std::cout << "\n[C] - Execute a form";
		std::cout << "\n[D] - Get the hell outta here" << std::endl;
		std::cin >> command;
		for (int i = 0; i < MAX_CMD_NUMBER; i++)
		{
			if (command.compare(command_list[i]) == 0 )
			{
				if (i == 3)
				{
					if (formTemplate)
						delete formTemplate;
					return ;
				}
				ex03_poc_doCommand(i, formTemplate, burList);
				errflag = 0;
			}
		}
		if (errflag)
			std::cout << "\nPlease insert a valid option. Number only." << std::endl;
		errflag = 1;
	}
}

void ex03_poc_doCommand(int index, Form *&formTemplate, Bureaucrat *burList)
{
	std::string knownForms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	if (index == 0)
	{
		Intern		factory;
		std::string formName;
		std::string formTarget;
		std::cout << "\n*You have decided to search for an Itern to make a form for you." << std::endl;
		if (formTemplate != NULL)
		{
			std::cout << "\tsince you still have a form, the Intern burns your old form" << std::endl;
			delete formTemplate;
			formTemplate = NULL;
		}
		std::cout << "[Intern] - Please insert the name of the form" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, formName);
		std::cout << "[Intern] - Please insert the target of the form" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, formTarget);
		formTemplate = factory.makeForm(formName, formTarget);
		if (formTemplate == NULL)
		{
			std::cout << "[Intern] - these are the forms I know: " << knownForms[0] << ", " + knownForms[1] + ", " << knownForms[2] << std::endl;
		}
		else
			std::cout << "*The intern handles you back a new form, it reads: Name[" << formTemplate->getName() << "] Target["<< formTemplate->getTarget() << "] GradeRequiredToSign[" << formTemplate->getGradeRequiredToSign() << "] GradeRequiredToExecute[" << formTemplate->getGradeRequiredToExecute() << "]" << std::endl;
	}
	else if (index == 1)
	{
		std::string burIdx;
		int			booth = -1;

		std::cout << "\n*You start searching for a bureaucrat to sign your form, there are a few cublicles:" << std::endl;
		for (int i = 0; i < 7; i++)
			std::cout << "\t[" << i << "]" << burList[i].getName() << "[" << burList[i].getGrade() << "]" << std::endl;
		std::cout << "Chose a booth to go to:" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, burIdx);
		std::istringstream iss(burIdx);
		if (iss >> booth && booth < 7 && booth >=0)
		{
			if (formTemplate == NULL)
			{
				std::cout << "The bureaucrat extends it's hands waiting for you to handle him the papers... You have no papers" << std::endl;
				return ;
			}
			std:: cout << "You handle the form to the bureacrat...." << std::endl;
			if (burList[booth].signForm(*formTemplate))
			{
				std::cout << "The bureaucrat handles the papers back to you. You head back to the entrance" << std::endl;
				return ;
			}
		}
		else
		{
			std::cout << "That is not a valid booth. You got lost in the bureau and decided to head back to the entrance..." << std::endl;
			return ;
		}
	}
	else if (index == 2)
	{
		std::string burIdx;
		int			booth = -1;

		std::cout << "\n*You start searching for a bureaucrat to execute your form, there are a few cublicles:" << std::endl;
		for (int i = 0; i < 7; i++)
			std::cout << "\t[" << i << "]" << burList[i].getName() << "[" << burList[i].getGrade() << "]" << std::endl;
		std::cout << "Chose a booth to go to:" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, burIdx);
		std::istringstream iss(burIdx);
		if (iss >> booth && booth < 7 && booth >=0)
		{
			if (formTemplate == NULL)
			{
				std::cout << "The bureaucrat extends it's hands waiting for you to handle him the papers... You have no papers" << std::endl;
				return ;
			}
			std:: cout << "You handle the form to the bureacrat...." << std::endl;
			if (burList[booth].executeForm(*formTemplate))
			{
				std::cout << "The bureaucrat executes your order and burns it. You head back to the entrance" << std::endl;
				delete formTemplate;
				formTemplate = NULL;
				return ;
			}
		}
		else
		{
			std::cout << "That is not a valid booth. You got lost in the bureau and decided to head back to the entrance..." << std::endl;
			return ;
		}
	}
	return ;
}

int main (int argc, char *argv[])
{
	std::string argument;
	std::string lError("Error, please use one of the following arguments: ex01 | ex02 | constructors | make_form | poc | ALL");
	if (argc > 2)
	{
		std::cerr << lError << std::endl;
		return 1;
	}
	if (argc == 1)
	{
		ex03_test_constructors();
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
	if (argument.compare("ex02") == 0)
	{
		test_ex02();
		return 0;
	}
	if (argument.compare("constuctors") == 0)
	{
		ex02_test_constructors();
		return 0;
	}
	if (argument.compare("make_form") == 0)
	{
		ex03_makeForm();
		return 0;
	}
	if (argument.compare("poc") == 0)
	{
		ex03_poc();
		return 0;
	}
	else if (argument.compare("ALL") == 0)
	{


		std::cout << "!!!!!!!!!!!!!!TESTING ALL THE THINGS!!!!!!!!!!!!!!11" << std::endl;
		std::cout << ".. except exceptions... and ex01 and ex02... " << std::endl;


 		ex03_test_constructors();
 		ex03_makeForm();
		ex03_poc();
		std::cout << "\n" << std::endl;
		print_timestamp();
		std::cout << "ALL TESTS COMPLETED SUCCESSFULLY!" << std::endl;
		return 0;
	}
	std::cerr << lError << std::endl;
	return 0;
}
