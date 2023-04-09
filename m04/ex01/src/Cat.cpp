/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:14 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/09 18:13:47 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_catBrain = new Brain;
	return ;
}

Cat::Cat(const Cat & instance)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = instance;
	return ;
}

Cat & Cat::operator=(const Cat & instance)
{
	std::cout << "Cat copy operator constructor called" << std::endl;

	std::cout << std::endl;

	if (this == &instance)
		return *this;
	this->type = instance.getType();
	if (this->_catBrain)
		delete this->_catBrain;
	if (typeid(*this) == typeid(instance))
		this->_catBrain = new Brain(*instance.getBrain());
	else
		this->_catBrain = new Brain;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor called" << std::endl;
	if (this->_catBrain)
	{
		delete this->_catBrain;
		this->_catBrain = NULL;
	}
	return ;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat argument constructor called [" + type + "]" << std::endl;
	this->_catBrain = new Brain;
	return ;
}

const Brain* Cat::getBrain(void) const
{
	return this->_catBrain;
}

void Cat::makeSound(void) const
{
	std::cout << this->getType() + " : meow" << std::endl;
}

void Cat::setBrain(Brain * brain)
{
	if (this->_catBrain)
		delete this->_catBrain;
	this->_catBrain = brain;
	return ;
}
