/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:13 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/18 15:56:39 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(int fixedPointNumber);
	Fixed(const Fixed &fixed);
	Fixed & operator=(Fixed const &fixed);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int					_fixedPointNumber;
	static const int	_factionalBits = 8;

};

#endif // FIXED_HPP
