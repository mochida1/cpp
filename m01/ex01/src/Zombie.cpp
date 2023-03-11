/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:18 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 17:24:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Creating zombie named " << name << std::endl;
	return ;
}

Zombie::Zombie(void) {
	std::cout << "Creating zombie" << std::endl;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << "Destroing [" << this->_name <<"]" << std::endl;
	return ;
}

void	Zombie::SetName(std::string name) {
	this->_name = name;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
