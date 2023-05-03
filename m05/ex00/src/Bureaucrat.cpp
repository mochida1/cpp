/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:57:00 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/01 20:03:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	std::cout << "[Default][150] bureaucrat created" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat & instance) : _name( instance.getName() ) {
	std::cout << "Copied Bureacrat:\t"  << instance << std::endl;
	*this = instance;
	return ;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & instance) {
	std::cout << "Copying grade of [" << instance.getName() << ":" << this->getGrade() << "] to [" << *this << "]" <<std::endl;
	this->_grade = instance.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat::Bureaucrat (std::string name, int grade)
: _name(name), _grade(grade) {
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
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void){
	std::cerr << "WARNING: Exception object [GradeTooHighException] destroyed!" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "\033[0;31m\t\tGrade TOO DAMN HIGH!\033[0m]";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void){
	std::cerr << "WARNING: Exception object [GradeTooLowException] constructed!" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void){
	std::cerr << "WARNING: Exception object [GradeTooLowException] destroyed!" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "\033[0;31m\t\tGrade TOO LOW!\033[0m]";
}

// non-member functions

std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &instance)
{
	outStream << "[" << instance.getName() << "], bureaucrat grade [" << instance.getGrade() << "]";
	return outStream;
}
