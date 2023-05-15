/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:43:31 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/14 21:34:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form(""), _name("PresidentialPardonForm"), _isSigned(false), _gradeRequiredToSign(25), _gradeRequiredToExecute(5) {
	// this->_name = "PresidentialPardonForm";
// PresidentialPardonForm::PresidentialPardonForm(void) : Form(""/* , "PresidentialPardonForm", false, 25, 5 */),  _name("PresidentialPardonForm"), _isSigned(false), _gradeRequiredToSign(145), _gradeRequiredToExecute(137) {
	return ;
}

// PresidentialPardonForm::PresidentialPardonForm(std::string target): Form(target, "PresidentialPardonForm", false, 145, 137) {
// 	return ;
// }

PresidentialPardonForm::~PresidentialPardonForm(){
}

// non
std::ostream &operator<<(std::ostream &outStream, Form const &instance);
