/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:43:31 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/21 17:25:22 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("", "PresidentialPardonForm", false, 25, 5) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, "PresidentialPardonForm", false, 25, 5) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Argument constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & instance) : Form(instance.getTarget(), instance.getName(), instance.getIsSigned(), 25, 5) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & instance) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] copy operator called" << std::endl;
	Form::operator=(instance);
	this->target_ = instance.getTarget();
	this->_isSigned = instance.getIsSigned();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void	PresidentialPardonForm::_doFormAction(void) const{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// non member functions
std::ostream &operator<<(std::ostream &outStream, PresidentialPardonForm const &instance)
{
	if (VERBOSE >=3)
		std::cout << "[PresidentialPardonForm] insertion operator overload called: " << std::endl;

	outStream << "name [" << instance.getName() << "] , target[" << instance.getTarget() << "] , isSigned [" << \
		((instance.getIsSigned() == true) ? "true" : "false")  << "], gradeRequiredToSign [" << \
		instance.getGradeRequiredToSign() << "], gradeRequiredToExecute [" << \
		instance.getGradeRequiredToExecute() << "]";
	return outStream;
}
