/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:13 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/02 21:28:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int fixedPointNumber);
	Fixed(const float fixedPointNumber);
	Fixed(const Fixed &fixed);
	Fixed & operator=(Fixed const &fixed);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	void	printFixedMin(void);
	void	printFixedMax(void);
	void	printMinusOne(void);
	void	printInt(void);
	void	printBinary(void *ptrToValue, int bitSize);

	// comparison: >, <, >=, <=, == !=
	bool	operator>(Fixed const &toCompare) const;
	bool	operator<(Fixed const &toCompare) const;
	bool	operator>=(Fixed const &toCompare) const;
	bool	operator<=(Fixed const &toCompare) const;
	bool	operator==(Fixed const &toCompare) const;
	bool	operator!=(Fixed const &toCompare) const;

	// arithmetic: +, -, *, /

	Fixed	operator+(Fixed const &toOperate);
	Fixed	operator-(Fixed const &toOperate);
	Fixed	operator*(Fixed const &toOperate);
	Fixed	operator/(Fixed const &toOperate);

	// in(de)crement: ++ --;
	Fixed	operator++(int);
	Fixed	&operator++(void);
	Fixed	operator--(int);
	Fixed	&operator--(void);

	// min maxes
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);

private:
	int					_fixedPointNumber;
	static const int	_fractionalBits = 8;
	static const int	_integerPart = 0xffffff00;
	static const int	_floatPart = 0x000000ff;
	static const int	_fixedMax = 0x7fffff;
	static const int	_fixedMin = 0x800000;
};
std::ostream &operator<<(std::ostream &outStream, Fixed const &instance); // this has to be declard as a nonmember function because of the implicit *this* parameter.

#endif // FIXED_HPP
