/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:43:31 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/17 22:57:58 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("", "PresidentialPardonForm", false, 25, 5), _gradeRequiredToSign(25), _gradeRequiredToExecute(5) {
	if (VERBOSE)
		std::cout << "defaul constructor for [PresidentialPardonForm] called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, "PresidentialPardonForm", false, 25, 5), _gradeRequiredToSign(25), _gradeRequiredToExecute(5) {
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

// non
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
