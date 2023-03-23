/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:13 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/19 13:33:39 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// +, -, *, and /
class Fixed {
public:
	Fixed(void);
	Fixed(int fixedPointNumber);
	Fixed(const Fixed &fixed);
	Fixed & operator=(Fixed const &fixed);
	Fixed operator>(Fixed const &fixed);
	Fixed operator>=(Fixed const &fixed);
	Fixed operator<=(Fixed const &fixed);
	Fixed operator==(Fixed const &fixed);
	Fixed operator!=(Fixed const &fixed);
	Fixed operator+(Fixed const &fixed);
	Fixed operator-(Fixed const &fixed);
	Fixed operator*(Fixed const &fixed);
	Fixed operator/(Fixed const &fixed);
	Fixed operator++(int);
	Fixed & operator++(void);
	Fixed operator--(int);
	Fixed & operator--(void);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	static Fixed & min(Fixed &a, Fixed &b);

private:
	int					_fixedPointNumber;
	static const int	_factionalBits = 8;

};
// A static member function min that takes as parameters two references on fixed-point
// numbers, and returns a reference to the smallest one.
// • A static member function min that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the smallest one.
// • A static member function max that takes as parameters two references on fixed-point
// numbers, and returns a reference to the greatest one.
// • A static member function max that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the greatest one.

#endif // FIXED_HPP
