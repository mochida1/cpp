/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:14:25 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 19:52:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &anyWeapon) : _name(name), _weapon(&anyWeapon) {
	return ;
}

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void	HumanB::setWeapon(Weapon &anyWeapon)
{
	this->_weapon = &anyWeapon;
	return ;
}

void	HumanB::attack(void) {
	if (this->_weapon != NULL)
	{
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
		return ;
	}
	std::cout << this->_name << " does some unnarmed kung fu!" << std::endl;
}

std::string const HumanB::getName(void)
{
	return (this->_name);
}
