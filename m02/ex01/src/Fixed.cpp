/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:45:21 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/22 21:26:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
}

Fixed::Fixed(const int fixedPointNumber) : _fixedPointNumber(fixedPointNumber << 8)
{
	std::cout << "Argument construcor called" << std::endl;
	if (fixedPointNumber > this->_fixedMax)
	{
		std::cerr << "Error: passed value is greater than " << this->_fixedMax << std::endl;
		this->_fixedPointNumber = 0;
		return ;
	}
	if (fixedPointNumber < this->_fixedMin)
	{
		std::cerr << "Error: passed value is lower than " << this->_fixedMin << std::endl;
		this->_fixedPointNumber = 0;
		return ;
	}
	return;
}

Fixed::Fixed(const float fixedPointNumber)
{
	(void) (fixedPointNumber);
	std::cout << "Argument construcor called" << std::endl;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed & Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNumber = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumber);
}

void	Fixed::printFixedMin(void)
{
	int min;

	min = this->_fixedMin;
	std::cout << "Fixed min: [" << min << "]" << std::endl;
}

void	Fixed::printFixedMax(void)
{
	std::cout << "Fixed max: [" << this->_fixedMax << "]" << std::endl;
}

void	Fixed::printOne(void)
{
	std::cout << "This is -1 [" << (int) (0xffffffff) << "]" << std::endl;
	std::cout << "This should be -1: [" << (int) ((this->_fixedMax ^ this->_fixedMin) | 0xff000000) << "]" << std::endl;
}

void	Fixed::printInt(void)
{
	std::cout << "Int is: " << (int) (this->_fixedPointNumber >> 8) << std::endl;
}
