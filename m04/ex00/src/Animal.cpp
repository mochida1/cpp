/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:11 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 20:25:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal & instance)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = instance;
	return ;
}

Animal & Animal::operator=(const Animal & instance)
{
	std::cout << "Animal copy operator constructor called" << std::endl;
	this->type = instance.getType();
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
	return ;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal argument constructor called [" + type + "]" << std::endl;
	return ;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << "A generic sound of an animal..." << std::endl;
}
