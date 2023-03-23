/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:13 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/22 21:14:02 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
	void	printOne(void);
	void	printInt(void);

private:
	int					_fixedPointNumber;
	static const int	_fractionalBits = 8;
	static const int			_integerPart = 0xffffff00;
	static const int			_floatPart = 0x000000ff;
	static const int			_fixedMax = 0x7fffff;
	static const int			_fixedMin = 0x800000;
};

#endif // FIXED_HPP
