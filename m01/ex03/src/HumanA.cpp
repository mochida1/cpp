/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:05:20 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 19:51:03 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &anyWeapon) : _name(name), _weapon(&anyWeapon) {
	return ;
}

HumanA::~HumanA(void) {
	return ;
}

void HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

std::string const HumanA::getName(void)
{
	return (this->_name);
}
