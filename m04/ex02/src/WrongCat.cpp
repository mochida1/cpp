/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:45 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/03 19:47:43 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat & instance)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = instance;
	return ;
}

WrongCat & WrongCat::operator=(const WrongCat & instance)
{
	std::cout << "WrongCat copy operator constructor called" << std::endl;
	this->type = instance.getType();
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat argument constructor called [" + type + "]" << std::endl;
	return ;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->getType() + " : mimimimimimimimi" << std::endl;
}
