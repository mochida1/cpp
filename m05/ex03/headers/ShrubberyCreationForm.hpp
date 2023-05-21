/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:35:23 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/21 16:25:07 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

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
	void				_doFormAction(void) const;
	std::string			_createTrees(void) const;
};

std::ostream &operator<<(std::ostream &outStream, ShrubberyCreationForm const &instance);

#endif // SHRUBBERYCREATIONFORM_HPP
