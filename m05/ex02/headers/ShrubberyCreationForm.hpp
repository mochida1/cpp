/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:35:23 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/20 18:07:57 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
public:
// OCF-----------------------
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm & instance);
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm & instance);
	~ShrubberyCreationForm(void);
// --------------------------
protected:
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeRequiredToSign;
	const int			_gradeRequiredToExecute;
	void				_doFormAction(void) const;
};

std::ostream &operator<<(std::ostream &outStream, ShrubberyCreationForm const &instance);

#endif // SHRUBBERYCREATIONFORM_HPP
