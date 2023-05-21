/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:43:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/20 17:38:00 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("", "RobotomyRequestForm", false, 75, 45), _gradeRequiredToSign(75), _gradeRequiredToExecute(45) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, "RobotomyRequestForm", false, 75, 45), _gradeRequiredToSign(75), _gradeRequiredToExecute(45) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Argument constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & instance) : Form(instance.getTarget(), instance.getName(), false, 75, 45), _gradeRequiredToSign(75), _gradeRequiredToExecute(45) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & instance) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] copy operator called" << std::endl;
	Form::operator=(instance);
	this->target_ = instance.getTarget();
	this->_isSigned = instance.getIsSigned();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void	RobotomyRequestForm::_doFormAction(void) const{
	int random;
	std::srand(std::time(0));

	random = std::rand() % 2;
	std::cout << "* drilling noises *" << std::endl;
	if(random)
		std::cout << this->getTarget() << " has been successfully robotomized 50% of the time;" << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}

// non member functions
std::ostream &operator<<(std::ostream &outStream, RobotomyRequestForm const &instance)
{
	if (VERBOSE >=3)
		std::cout << "[RobotomyRequestForm] insertion operator overload called: " << std::endl;

	outStream << "name [" << instance.getName() << "] , target[" << instance.getTarget() << "] , isSigned [" << \
		((instance.getIsSigned() == true) ? "true" : "false")  << "], gradeRequiredToSign [" << \
		instance.getGradeRequiredToSign() << "], gradeRequiredToExecute [" << \
		instance.getGradeRequiredToExecute() << "]";
	return outStream;
}
