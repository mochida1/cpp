/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:57:00 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/20 16:50:18 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	try {
		this->_testGrade(this->_grade);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	if (VERBOSE)
		std::cout << "[Default][150] bureaucrat created" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat & instance) : _name( instance.getName() ) {
	*this = instance;
	try {
		this->_testGrade(this->_grade);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	if (VERBOSE)
		std::cout << "Copied Bureaucrat:\t"  << instance << std::endl;
	return ;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & instance) {
	if (VERBOSE)
		std::cout << "Copying grade of [" << instance.getName() << ":" << instance.getGrade() << "] to [" << this->getName() << "]" <<std::endl;
	this->_grade = instance.getGrade();

	try {
		this->_testGrade(this->_grade);
	}
	catch (const std::exception& e)	{
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
		std::cout << this->getName() << " tried cheating the bureacracy. Resetting grade to 150" << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	if (VERBOSE)
		std::cout << "Bureaucrat default destructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat (std::string name, int grade)
: _name(name), _grade(grade) {
	try {
		this->_testGrade(grade);
	}
	catch (const std::exception& e)	{
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
		std::cout << this->getName() << " tried cheating the bureacracy. Resetting grade to 150" << std::endl;
	}
	if (VERBOSE)
		std::cout << "Bureaucrat copy constructor called: [" << this->getName() << "][" << this->getGrade() << "]" << std::endl;
	return ;
}

const std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void){
	std::cerr << "WARNING: Exception object [GradeTooHighException] constructed!" << std::endl;
	return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void){
	std::cerr << "WARNING: Exception object [GradeTooHighException] destroyed!" << std::endl;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "\033[0;31m\t\tGrade TOO DAMN HIGH!\033[0m]";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void){
	std::cerr << "WARNING: Exception object [GradeTooLowException] constructed!" << std::endl;
	return ;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void){
	std::cerr << "WARNING: Exception object [GradeTooLowException] destroyed!" << std::endl;
	return ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "\033[0;31m\t\tGrade TOO LOW!\033[0m]";
}

bool	Bureaucrat::_testGrade(int grade) const{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return false;
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return false;
	}
	return true;
}

void	Bureaucrat::setGrade(int grade){
	try {
		this->_testGrade(grade);
	}
	catch (const std::exception& e)	{
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
		std::cout << this->getName() << " tried cheating the bureacracy. Resetting grade to 150" << std::endl;
		return ;
	}
	this->_grade = grade;
	return ;
}

void	Bureaucrat::_validateGrade(int grade){
	try {
		this->_testGrade(grade);
	}
	catch (const std::exception& e)	{
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
		std::cout << this->getName() << " tried cheating the bureacracy. Resetting grade to 150" << std::endl;
		return ;
	}
}

void	Bureaucrat::increaseGrade(int amount){
	if (VERBOSE)
		std::cout << "Increasing [" << this->_name <<"] by " << amount << std::endl;

	this->_grade -= amount;
	this->_validateGrade(this->_grade);

	if (VERBOSE)
		std::cout << this->_name << " grade now is " << this->_grade << std::endl;
	return;
}

void Bureaucrat::decreaseGrade(int amount){
	if (VERBOSE)
		std::cout << "Dereasing [" << this->_name <<"] by " << amount << std::endl;

	this->_grade += amount;
	this->_validateGrade(this->_grade);

	if (VERBOSE)
		std::cout << this->_name << " grade now is " << this->_grade << std::endl;

	return ;
}

void	Bureaucrat::increaseGrade(void){
	if (VERBOSE)
		std::cout << "Increasing [" << this->_name <<"] by 1" << std::endl;

	this->_grade--;
	this->_validateGrade(this->_grade);

	if (VERBOSE)
		std::cout << this->_name << " grade now is " << this->_grade << std::endl;
	return;
}

void Bureaucrat::decreaseGrade(void){
	if (VERBOSE)
		std::cout << "Dereasing [" << this->_name <<"] by 1" << std::endl;

	this->_grade++;
	this->_validateGrade(this->_grade);

	if (VERBOSE)
		std::cout << this->_name << " grade now is " << this->_grade << std::endl;

	return ;
}

bool Bureaucrat::signForm(Form & instance){
	if (VERBOSE)
		std::cout << *this << " trying to sign form " << instance << std::endl;
	return instance.beSigned(*this);
}

bool Bureaucrat::executeForm(Form const & form){
	int	rc;

	rc = 0;
	if (this->getGrade() > form.getGradeRequiredToExecute())
		rc |= 1;
	if (form.getIsSigned() == false)
		rc |= 2;
	if (rc == 0)
	{
		std::cout << "[" << this->getName() << "] executed form [" << form.getName() << "]" << std::endl;
		form.execute(*this);
		return true;
	}

	std::cout << "Form [" << form.getName() << "] couldnt be executed by [" << this->getName() << "] because ";
	if (rc & 1)
		std::cout << "Bureaucrat's grade was too low; ";
	if (rc & 2)
		std::cout << "Form was not signed; ";
	std::cout << std::endl;
	return false;
}

// non-member functions

std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &instance)
{
	outStream << "[" << instance.getName() << "], bureaucrat grade [" << instance.getGrade() << "]";
	return outStream;
}
