/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:34:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/21 15:48:57 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"


/*
	PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/
class PresidentialPardonForm : public Form
{
public:
// OCF-----------------------
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm & instance);
	PresidentialPardonForm & operator=(const PresidentialPardonForm & instance);
	~PresidentialPardonForm(void);
// --------------------------
protected:
private:
	const std::string	_name;
	bool				_isSigned;
	void				_doFormAction(void) const;
};

std::ostream &operator<<(std::ostream &outStream, PresidentialPardonForm const &instance);

#endif // PRESIDENTIALPARDONFORM_HPP
