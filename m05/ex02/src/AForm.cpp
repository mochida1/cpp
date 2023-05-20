/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/19 23:24:31 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(void) :
target_(""),
_name("defForm"),
_isSigned(false),
_gradeRequiredToSign(150),
_gradeRequiredToExecute(150) {
	if (VERBOSE)
		std::cout << "Constructing default form: [name=defForm], [_isSigned=false], [_gradeRequiredToSign=150], [_gradeRequiredToExecute=150]" << std::endl;
	return ;
}

Form::Form(std::string target) :
target_(target),
_name("defForm"),
_isSigned(false),
_gradeRequiredToSign(150),
_gradeRequiredToExecute(150) {
	if (VERBOSE)
		std::cout << "Constructing default form: [name=defForm], [_isSigned=false], [_gradeRequiredToSign=150], [_gradeRequiredToExecute=150]" << std::endl;
	return ;
}

Form::Form(const Form & instance) :
target_(instance.getTarget()),
_name(instance.getName()),
_isSigned(instance.getIsSigned()),
_gradeRequiredToSign(instance.getGradeRequiredToSign()),
_gradeRequiredToExecute(instance.getGradeRequiredToExecute()) {
	if(VERBOSE)
		std::cout << "Constructing copy from [" << instance << "]" << std::endl;
	return;
}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) :
target_(""),
_name(name),
_isSigned(false),
_gradeRequiredToSign(gradeRequiredToSign),
_gradeRequiredToExecute(gradeRequiredToExecute) {
	if (VERBOSE)
		std::cout << "Form argument constructor: " << *this << std::endl;

	this->_validateGrade(gradeRequiredToSign);
	this->_validateGrade(gradeRequiredToExecute);
	return ;
}

Form::Form(std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute) :
target_(""),
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

Form::Form(std::string target, std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute) :
target_(target),
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
const std::string	Form::getName(void) const{
	if (VERBOSE >= 3)
		std::cout << "getName() called: " << this->_name << std::endl;
	return this->_name;
}
int			Form::getGradeRequiredToSign(void) const{
	if (VERBOSE >= 3)
		std::cout << "getGradeRequiredToSign() called: " << this->_gradeRequiredToSign << std::endl;
	return this->_gradeRequiredToSign;
}

int			Form::getGradeRequiredToExecute(void) const{
	if (VERBOSE >= 3)
		std::cout << "getGradeRequiredToExecute() called: " << this->_gradeRequiredToExecute << std::endl;
	return this->_gradeRequiredToExecute;
}

bool				Form::getIsSigned(void) const{
	if (VERBOSE >= 3)
		std::cout << "getIsSigned() called: " << this->_isSigned << std::endl;
	return this->_isSigned;
}

const std::string	Form::getTarget(void) const {
	if (VERBOSE >= 3)
		std::cout << "getTarget() called: " << this->target_ << std::endl;
	return this->target_;

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
		std::cout << "setIsSigned(bool state) called; instance state: "<< this->_isSigned;
	this->_isSigned = (this->_isSigned == true) ? false : true;
	if (VERBOSE >= 3)
		std::cout << "\t new state: " << this->_isSigned  << std::endl;
	return this->_isSigned;
}

bool				Form::setTarget(std::string target){
	if (VERBOSE >= 3)
		std::cout << "setTarget() called; target: " << target  << " instance target: "<< this->target_;
	this->target_ = target;
	if (this->target_.compare(target) != 0)
	{
		std::cerr << "WARNING! Couldn't copy target to instace: " << *this << std::endl;
		return false;
	}
	if (&this->target_ == &target)
	{
		std::cerr << "WARNING! setTarget doing a shallow copy!" << std::endl;
		return false;
	}
	return true;
}

// CUSTOM

// returns true if bureaucrat has signed form;
bool				Form::beSigned(Bureaucrat instance){
	if (VERBOSE >= 3)
		std::cout << *this << ":beSigned()\targ: " << instance << std::endl;
	int rc;
	rc = 0;

	rc = this->_validateSignRequirements(instance);
	if (rc)
	{
		std::cout << instance.getName() << " couldn't sign " << this->_name << " because";
		if (rc & 1)
			std::cout << " grade is too low (" << instance.getGrade() << "). Required(" << this->_gradeRequiredToSign << ");";
		if (rc & 2)
			std::cout << " form is already signed;";
		std::cout << std::endl;
		return false;
	}
	this->setIsSigned(true);
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

int					Form::_validateExecuteRequirements(Bureaucrat instance) const{
	int rc;

	rc = 0;
	if (VERBOSE >= 3)
		std::cout << "validating execute requirements..." << std::endl;

	if (this->getGradeRequiredToExecute() < instance.getGrade())
	{
		rc |= 1;
		throw Form::ExecuteGradeTooLowException();
	}
	if (this->_isSigned == true)
	{
		rc |= 2;
		throw Form::ExecuteFormUnsignedException();
	}
	if (VERBOSE >= 3)
		std::cout << "execute requirements validated as " << ((rc == 0) ? "successful" : "failed") << std::endl;
	return rc;
}

bool Form::execute(Bureaucrat const & executor) const {
	int	rc;

	rc = 0;
	try {
		rc = this->_validateExecuteRequirements(executor);
		if (rc)
		{
			std::cerr << "CRITICAL ERROR: ["<< executor.getName() << "] tried to ";
			if (rc & 1)
				std::cerr << "execute a form[" << this->getName() << "]with higher grade[" << this->_gradeRequiredToExecute << "] than his [" << executor.getGrade() << "] ";
			if (rc & 2)
				std::cerr << "execute an unsigned form [" << this->getName() <<"]";
			std::cerr << std::endl;
		}
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
		std::cout << this->getName() << " got f'd up by " << executor.getName() << std::endl;
		return false;
	}
	this->_doFormAction();
	return true;
}

void Form::_doFormAction(void) const{
	std::cout << "WARNING! Doing base form action!" << std::endl;
	return ;
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

void 		Form::print(void) const {
	std::cout << "name [" << this->getName() << "] , isSigned [" <<\
		((this->getIsSigned() == true) ? "true" : "false")  << "], gradeRequiredToSign [" << \
		this->getGradeRequiredToSign() << "], gradeRequiredToExecute [" << \
		this->getGradeRequiredToExecute() << "]";
}
// non-member functions

std::ostream &operator<<(std::ostream &outStream, Form const &instance)
{
	if (VERBOSE >=3)
		std::cout << "insertion operator overload called: " << std::endl;

	instance.print();
	return outStream;
}
