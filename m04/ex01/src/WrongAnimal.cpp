/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:47 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 21:06:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal & instance)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = instance;
	return ;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & instance)
{
	std::cout << "WrongAnimal copy operator constructor called" << std::endl;
	this->type = instance.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal argument constructor called [" + type + "]" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "A wrong generic sound of a wrong animal..." << std::endl;
}
