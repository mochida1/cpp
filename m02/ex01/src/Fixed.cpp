/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:45:21 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/30 21:53:55 by hmochida         ###   ########.fr       */
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
	std::cout << "toInt is: " << this->toInt() << std::endl;
	if (this->_fixedPointNumber > this->_fixedMax)
	{
		std::cerr << "Error: passed value ["<< fixedPointNumber <<"] is greater than " << this->_fixedMax << std::endl;
		this->_fixedPointNumber = 0;
		return ;
	}
	if (fixedPointNumber < this->_fixedMin * -1)
	{
		std::cerr << "Error: passed value ["<< fixedPointNumber <<"] is lower than " << this->_fixedMin << std::endl;
		this->_fixedPointNumber = 0;
		return ;
	}
	return;
}

// seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
Fixed::Fixed(const float fixedPointNumber)
{
	int fl = *(int*)&fixedPointNumber;
	int exponent;
	int mantissa;

	exponent = 0;
	mantissa = 0;
	this->printBinary(&mantissa, 32);
	this->printBinary(&exponent, 32);
	for (int i = 0; i < 31; i++)
	{
		if (i < 23)
		{
			if (((1 << i) & fl))
				mantissa += 1 << i;
		}
		else
			if (((1 << i) & fl))
				exponent += 1 << (i -23);
	}
	// exponent -= 127;
	std::cout << "Mantissa of [" << fixedPointNumber << "] is [" <<  mantissa << "]" << std::endl;
	std::cout << "Exponent of [" << fixedPointNumber << "] is [" <<  exponent << "]" << std::endl;
	if (fixedPointNumber < 0)
		this->_fixedPointNumber |= 0x80000000;
	this->printBinary(&mantissa, 32);
	this->printBinary(&exponent, 32);
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

void	Fixed::printMinusOne(void)
{
	std::cout << "This is -1 [" << (int) (0xffffffff) << "]" << std::endl;
	std::cout << "This should be -1: [" << (int) ((this->_fixedMax ^ this->_fixedMin) | 0xff000000) << "]" << std::endl;
}

void	Fixed::printInt(void)
{
	std::cout << "Int is: " << (int) (this->_fixedPointNumber >> 8) << std::endl;
}

int	Fixed::toInt(void) const
{
	if (this->_fixedPointNumber & 0x80000000)
		return ((this->_fixedPointNumber >> 8) | 0xff000000);
	return (this->_fixedPointNumber >> 8);
}

float	Fixed::toFloat(void) const
{
	return 0;
}

void	Fixed::printBinary(void *ptrToValue, int bitSize)
{
	if (bitSize > 32)
	{
		std::cerr << "Error(printBinary): bitSize too big" << std::endl;
		return ;
	}
	int value = *(int*)ptrToValue;
	std::cout << value << " binary in binary: ";
	for (int i = bitSize - 1; i > 0; i--)
	{
		std::cout << (bool)((1 << i) & value);
	}
	std::cout << std::endl;
	return ;
}
