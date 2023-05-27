/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:39:28 by mochida           #+#    #+#             */
/*   Updated: 2023/05/27 15:48:36 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTER_HPP

#include "AForm.hpp"

class Intern{
	public:
	// OCF -------------------------
	Intern(void);
	~Intern(void);
	Intern(const Intern & instance);
	Intern & operator=(const Intern & instance);
	// ------------------------- OCF
	Form * makeForm(std::string formName, std::string target);
	protected:
	private:
	Form * _createPPF(std::string target);
	Form * _createRRF(std::string target);
	Form * _createSCF(std::string target);
	Form * _error(std::string target);
};

#endif // INTERN_HPP