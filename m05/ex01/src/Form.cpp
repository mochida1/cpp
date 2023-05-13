/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/13 20:25:10 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
_name("defForm"),
_isSigned(false),
_gradeRequiredToSign(150),
_gradeRequiredToExecute(150) {
	if (VERBOSE)
		std::cout << "Constructing default form: [name=defForm], [_isSigned=false], [_gradeRequiredToSign=150], [_gradeRequiredToExecute=150]" << std::endl;
	return ;
}

Form::Form(std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute) :
_name(name),
_isSigned(isSigned),
_gradeRequiredToSign(gradeRequiredToSign),
_gradeRequiredToExecute(gradeRequiredToExecute) {
	if (VERBOSE)
		std::cout << "Form argument constructor: " << *this << std::endl;

	this->_validateGrade(gradeRequiredToSign);
	this->_validateGrade(gradeRequiredToExecute);
	return ;
}

Form::~Form() {
	if (VERBOSE)
		std::cout << "Burning form ["  << this->_name << "]" << std::endl;
	return ;
}

Form & Form::operator=(const Form & instance) {
	if (VERBOSE)
		std::cout << "Copying signed status of [" << instance.getName() << "] to [" << this->getName() << "]" << std::endl;
	this->_isSigned = instance.getIsSigned();
	return *this;
}

//GETTERS
const std::string	Form::getName() const{
	if (VERBOSE >= 3)
		std::cout << "getName() called: " << this->_name << std::endl;
	return this->_name;
}
int			Form::getGradeRequiredToSign() const{
	if (VERBOSE >= 3)
		std::cout << "getGradeRequiredToSign() called: " << this->_gradeRequiredToSign << std::endl;
	return this->_gradeRequiredToSign;
}

int			Form::getGradeRequiredToExecute() const{
	if (VERBOSE >= 3)
		std::cout << "getGradeRequiredToExecute() called: " << this->_gradeRequiredToExecute << std::endl;
	return this->_gradeRequiredToExecute;
}

bool				Form::getIsSigned() const{
	if (VERBOSE >= 3)
		std::cout << "geIsSigned() called: " << this->_isSigned << std::endl;
	return this->_isSigned;
}

// SETTERS

bool				Form::setIsSigned(bool state){
	if (VERBOSE >= 3)
		std::cout << "setIsSigned(bool state) called state: " << state  << " instance state: "<< this->_isSigned;
	this->_isSigned = state;
	if (VERBOSE >= 3)
		std::cout << "\t new state: " << this->_isSigned  << std::endl;
	return this->_isSigned;
}
bool				Form::setIsSigned(void){
	if (VERBOSE >= 3)
		std::cout << "setIsSigned(bool state) called: " << " instance state: "<< this->_isSigned;
	this->_isSigned = (this->_isSigned == true) ? false : true;
	if (VERBOSE >= 3)
		std::cout << "\t new state: " << this->_isSigned  << std::endl;
	return this->_isSigned;
}

// returns true if bureaucrat has signed form;
bool				Form::beSigned(Bureaucrat instance){
	if (VERBOSE >= 3)
		std::cout << *this << ":beSigned()\targ: " << instance << std::endl;
	int rc;
	rc = 0;

	rc = this->_validateSignRequirements(instance);
	if (rc)
	{
		std::cout << instance.getName() << " couldn't sign " << this->_name << "because";
		if (rc & 1)
			std::cout << " grade is too low (" << instance.getGrade() << "). Required(" << this->_gradeRequiredToSign << ");";
		if (rc & 2)
			std::cout << " form is already signed;";
		std::cout << std::endl;
		return false;
	}
	std::cout << instance.getName() << " signed " << this->getName() << std::endl;
	return true;
}

// PRIVATE PARTS
bool	Form::_testGrade(int grade) const{
	if (VERBOSE >= 3)
		std::cout << *this << "@_testGrade(int grade): " << grade << std::endl;
	if (grade < 1)
	{
		if (VERBOSE)
			std::cerr << this->_name << ": Grade too high, throwing exception!" << std::endl;
		throw Form::GradeTooHighException();
		return false;
	}
	else if (grade > 150)
	{
		if (VERBOSE)
			std::cerr << this->_name << ": Grade too low, throwing exception!" << std::endl;
		throw Form::GradeTooLowException();
		return false;
	}
	if (VERBOSE >= 3)
		std::cout << *this << " successfully tested grade [" << grade << "]" << std::endl;
	return true;
}

bool	Form::_validateGrade(int grade){
	if (VERBOSE >= 3)
		std::cout << "validating grade [" << grade << "]" << std::endl;
	try {
		this->_testGrade(grade);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
		std::cout << this->getName() << " invalid form!" << std::endl;
		return false;
	}
	if (VERBOSE >= 3)
		std::cout << "grade validated successfully!" << std::endl;
	return true;
}

int					Form::_validateSignRequirements(Bureaucrat instance) const{
	if (VERBOSE >= 3)
		std::cout << "validating sign requirements..." << std::endl;

	int rc;
	rc = 0;
	if (this->getGradeRequiredToSign() < instance.getGrade())
		rc |= 1;
	if (this->_isSigned == true)
		rc |= 2;

	if (VERBOSE >= 3)
		std::cout << "sign requirements validated as " << ((rc == 0) ? "successful" : "failed") << std::endl;
	return rc;
}

// EXCEPTIONS

Form::GradeTooHighException::GradeTooHighException(void){
	std::cerr << "WARNING: Exception object [GradeTooHighException] constructed!" << std::endl;
	return ;
}

Form::GradeTooHighException::~GradeTooHighException(void){
	std::cerr << "WARNING: Exception object [GradeTooHighException] destroyed!" << std::endl;
	return ;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "\033[0;31m\t\tGrade TOO DAMN HIGH!\033[0m]";
}

Form::GradeTooLowException::GradeTooLowException(void){
	std::cerr << "WARNING: Exception object [GradeTooLowException] constructed!" << std::endl;
	return ;
}

Form::GradeTooLowException::~GradeTooLowException(void){
	std::cerr << "WARNING: Exception object [GradeTooLowException] destroyed!" << std::endl;
	return ;
}

const char* Form::GradeTooLowException::what() const throw(){
	return "\033[0;31m\t\tGrade TOO LOW!\033[0m]";
}

// non-member functions

std::ostream &operator<<(std::ostream &outStream, Form const &instance)
{
	if (VERBOSE >=3)
		std::cout << "insertiong operator overload called: " << std::endl;

	outStream << "name [" << instance.getName() << "] , isSigned [" <<\
		((instance.getIsSigned() == true) ? "true" : "false")  << "], gradeRequiredToSign [" << \
		instance.getGradeRequiredToSign() << "], gradeRequiredToExecute [" << \
		instance.getGradeRequiredToExecute() << "]";
	return outStream;
}
