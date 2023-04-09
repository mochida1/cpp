/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:14 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 20:57:57 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
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
	this->type = instance.getType();
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor called" << std::endl;
	return ;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat argument constructor called [" + type + "]" << std::endl;
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << this->getType() + " : meow" << std::endl;
}
