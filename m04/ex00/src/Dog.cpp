/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:16 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 20:22:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	return ;
}

Dog::Dog(const Dog & instance)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = instance;
	return ;
}

Dog & Dog::operator=(const Dog & instance)
{
	std::cout << "Dog copy operator constructor called" << std::endl;
	this->type = instance.getType();
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor called" << std::endl;
	return ;
}

Dog::Dog(std::string type) : type(type)
{
	std::cout << "Dog argument constructor called [" + type + "]" << std::endl;
	return ;
}

std::string Dog::getType(void) const
{
	return this->type;
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() + " : woof" << std::endl;
}
