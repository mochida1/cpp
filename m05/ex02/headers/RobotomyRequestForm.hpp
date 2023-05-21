/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:35:17 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/21 15:51:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

/*
	RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
*/
class RobotomyRequestForm : public Form
{
public:
// OCF-----------------------
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm & instance);
	RobotomyRequestForm & operator=(const RobotomyRequestForm & instance);
	~RobotomyRequestForm(void);
// --------------------------
protected:
private:
	const std::string	_name;
	bool				_isSigned;
	void				_doFormAction(void) const;
};

std::ostream &operator<<(std::ostream &outStream, RobotomyRequestForm const &instance);

#endif // ROBOTOMYREQUESTFORM_HPP
