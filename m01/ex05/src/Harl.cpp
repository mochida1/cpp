/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:41:05 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 20:39:15 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	this->_debugMessage = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	this->_infoMessage = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	this->_warningMessage = "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	this->_errorMessage = "This is unacceptable! I want to speak to the manager now.";
	return ;
}

Harl::~Harl(void) {
	return ;
}

void	Harl::complain( std::string level ) {
	void (Harl::*funPtr[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[5] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int		max_levels;

	max_levels = *(&levels + 1) - levels;
	for (int idx = 0; idx < max_levels; idx++)
	{
		if (level.compare(levels[idx]) == 0)
		{
			(this->*funPtr[idx])();
			return ;
		}
	}
	std::cout << "No such level: " << level << std::endl;
	return ;
}

void	Harl::debug( void ) {
	std::cout << this->_debugMessage << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << this->_infoMessage << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::cout << this->_warningMessage << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::cout << this->_errorMessage << std::endl;
	return ;
}
