/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:43:36 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/21 15:51:41 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("", "ShrubberyCreationForm", false, 145, 137) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, "ShrubberyCreationForm", false, 145, 137) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Argument constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & instance) : Form(instance.getTarget(), instance.getName(), false, 145, 137) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & instance) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] copy operator called" << std::endl;
	Form::operator=(instance);
	this->target_ = instance.getTarget();
	this->_isSigned = instance.getIsSigned();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void	ShrubberyCreationForm::_doFormAction(void) const{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// non member functions
std::ostream &operator<<(std::ostream &outStream, ShrubberyCreationForm const &instance)
{
	if (VERBOSE >=3)
		std::cout << "[ShrubberyCreationForm] insertion operator overload called: " << std::endl;

	outStream << "name [" << instance.getName() << "] , target[" << instance.getTarget() << "] , isSigned [" << \
		((instance.getIsSigned() == true) ? "true" : "false")  << "], gradeRequiredToSign [" << \
		instance.getGradeRequiredToSign() << "], gradeRequiredToExecute [" << \
		instance.getGradeRequiredToExecute() << "]";
	return outStream;
}
