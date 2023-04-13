/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:16 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/13 19:50:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_dogBrain = new Brain;
	return ;
}

Dog::Dog(const Dog & instance)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_dogBrain = new Brain;
	*this = instance;
	return ;
}

Dog & Dog::operator=(const Dog & instance)
{
	std::cout << "Dog copy operator constructor called" << std::endl;

	if (this == &instance)
		return *this;
	this->type = instance.getType();
	if (this->_dogBrain)
		delete this->_dogBrain;
	if (typeid(*this) == typeid(instance))
		this->_dogBrain = new Brain(*instance.getBrain());
	else
		this->_dogBrain = new Brain;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor called" << std::endl;
	if (this->_dogBrain)
	{
		delete this->_dogBrain;
		this->_dogBrain = NULL;
	}
	return ;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog argument constructor called [" + type + "]" << std::endl;
	this->_dogBrain = new Brain;
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() + " : woof" << std::endl;
}

const Brain* Dog::getBrain(void) const
{
	return this->_dogBrain;
}

void Dog::setBrain(Brain * brain)
{
	if (this->_dogBrain)
		delete this->_dogBrain;
	this->_dogBrain = brain;
	return ;
}
