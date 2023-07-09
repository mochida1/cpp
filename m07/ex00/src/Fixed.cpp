/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:45:21 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/30 19:19:46 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixedPointNumber = 0;
	return ;
}

Fixed::Fixed(Fixed const &fixed)
{
	*this = fixed;
	return ;
}

Fixed::Fixed(const int fixedPointNumber) : _fixedPointNumber(fixedPointNumber << 8)
{
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
	return ;
}

Fixed::Fixed(const float fixedPointNumber)
{
	this->_fixedPointNumber = (int)roundf(fixedPointNumber * (1 << Fixed::_fractionalBits));
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed & Fixed::operator=(const Fixed &fixed)
{
	this->_fixedPointNumber = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
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

/*
	interprets the member fixedPointNumber bits as a float and does the math
	shenanigans to put it back to float.
*/
float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointNumber / (float)(1 << this->_fractionalBits));
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

	bool	Fixed::operator>(Fixed const &toCompare) const
	{
		return (this->toFloat() > toCompare.toFloat());
	}
	bool	Fixed::operator<(Fixed const &toCompare) const
	{
		return (this->toFloat() < toCompare.toFloat());
	}

	bool	Fixed::operator>=(Fixed const &toCompare) const
	{
		return (this->toFloat() >= toCompare.toFloat());
	}

	bool	Fixed::operator<=(Fixed const &toCompare) const
	{
		return (this->toFloat() <= toCompare.toFloat());
	}

	bool	Fixed::operator==(Fixed const &toCompare) const
	{
		return (this->getRawBits() == toCompare.getRawBits());
	}

	bool	Fixed::operator!=(Fixed const &toCompare) const
	{
		return (this->getRawBits() != toCompare.getRawBits());
	}

	// arithmetic: +, -, *, /

	Fixed	Fixed::operator+(Fixed const &toOperate)
	{
		return (this->toFloat() + toOperate.toFloat());
	}

	Fixed	Fixed::operator-(Fixed const &toOperate)
	{
		return (this->toFloat() - toOperate.toFloat());
	}

	Fixed	Fixed::operator*(Fixed const &toOperate)
	{
		return (this->toFloat() * toOperate.toFloat());
	}

	Fixed	Fixed::operator/(Fixed const &toOperate)
	{
		return (this->toFloat() / toOperate.toFloat());
	}


	// in(de)crement: ++ --
	/*
		returns a copy of the class so that the postfixed increment is read after
		the operation;
	*/
	Fixed	Fixed::operator++(int)
	{
		Fixed rv(*this);

		this->_fixedPointNumber++;
		return rv;
	}

	Fixed	&Fixed::operator++(void)
	{
		this->_fixedPointNumber++;
		return *this;
	}

	Fixed	Fixed::operator--(int)
	{
		Fixed rv(*this);

		this->_fixedPointNumber--;
		return rv;
	}

	Fixed	&Fixed::operator--(void)
	{
		this->_fixedPointNumber--;
		return *this;
	}

	// min maxes
	const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
	{
		if (a.toFloat() < b.toFloat())
			return a;
		return b;
	}

	const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
	{
		if (a.toFloat() > b.toFloat())
			return a;
		return b;
	}

	Fixed &Fixed::min(Fixed &a, Fixed &b)
	{
		if (a.toFloat() < b.toFloat())
			return a;
		return b;
	}

	Fixed &Fixed::max(Fixed &a, Fixed &b)
	{
		if (a.toFloat() > b.toFloat())
			return a;
		return b;
	}

std::ostream &operator<<(std::ostream &outStream, Fixed const &instance)
{
	outStream << instance.toFloat();
	return outStream;
}
