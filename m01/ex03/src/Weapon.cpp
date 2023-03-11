/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:15:14 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 18:32:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	return ;
}

Weapon::Weapon(std::string type) : _type(type) {
	return ;
}

std::string const &Weapon::getType(void) {
	return ((this->_type));
}

void Weapon::setType(std::string type) {
	this->_type = type;
	return ;
}
