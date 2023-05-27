/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:36:30 by mochida           #+#    #+#             */
/*   Updated: 2023/05/27 16:35:51 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// OCF -------------------------
Intern::Intern(void) {
	if (VERBOSE >= 3)
		std::cout << "[Intern] default constructor called;" << std::endl;
	return ;
}

Intern::~Intern(void) {
	if (VERBOSE >= 3)
		std::cout << "[Intern] default destructor called;" << std::endl;
	return ;
}

Intern::Intern(const Intern & instance) {
	if (VERBOSE >= 3)
		std::cout << "[Intern] copy constructor called;" << std::endl;
	*this = instance;
	return ;
}
Intern & Intern::operator=(const Intern & instance) {
	if (VERBOSE >= 3)
		std::cout << "[Intern] copy operator constructor called;" << std::endl;
	(void)(instance);
	return *this;
}
// ------------------------- OCF

Form * Intern::makeForm(std::string formName, std::string target) {
	Form * (Intern::*funPtr[3])(std::string target) = {
		&Intern::_createPPF,
		&Intern::_createRRF,
		&Intern::_createSCF,
	};
	std::string knownForms[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	int		max_knownForms;

	max_knownForms = *(&knownForms + 1) - knownForms;
	for (int idx = 0; idx < max_knownForms; idx++)
	{
		if ( formName.compare(knownForms[idx]) == 0 )
		{
			return (this->*funPtr[idx])(target);
		}
	}
	std::cerr << "Intern can't create such form: [" << formName << "]" << std::endl;
	return NULL;
}

Form * Intern::_createPPF(std::string target) {
	return (new PresidentialPardonForm(target));
}

Form * Intern::_createRRF(std::string target) {
	return (new RobotomyRequestForm(target));
}

Form * Intern::_createSCF(std::string target) {
	return (new ShrubberyCreationForm(target));
}