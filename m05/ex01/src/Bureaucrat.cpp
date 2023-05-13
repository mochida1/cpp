/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:57:00 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/12 21:12:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#ifndef VERBOSE
# define VERBOSE 1
#endif //VERBOSE

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
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooHighException();
		return false;
	}
	else if (grade < 1)
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

// non-member functions

std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &instance)
{
	outStream << "[" << instance.getName() << "], bureaucrat grade [" << instance.getGrade() << "]";
	return outStream;
}
