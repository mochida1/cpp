/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:37:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/02 21:31:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// std::cout << Fixed::min( a, b ) << std::endl; // not described in the subject

	return 0;
}

// int main(void)
// {
// 	float fl = 1234.56789;
// 	Fixed argConstr(fl);
// 	argConstr.printBinary(&fl, 32);
// 	std::cout << argConstr << std::endl;
// }

// int mainaa (void)
// {
// 	Fixed defConstr;
// 	Fixed argConstr(-42);
// 	Fixed argConstr(123.156f);
// 	Fixed copyConstr(defConstr);
// 	Fixed opConstr;

// 	opConstr = argConstr;

// 	std::cout << "def:  " << defConstr.getRawBits() << std::endl;
// 	std::cout << "arg:  " << argConstr.getRawBits() << std::endl;
// 	std::cout << "copy: " << copyConstr.getRawBits() << std::endl;
// 	std::cout << "op:   " << opConstr.getRawBits() << std::endl;

// 	defConstr.printFixedMin();
// 	defConstr.printFixedMax();
// 	defConstr.printMinusOne();
// 	argConstr.printInt();
// 	std::cout << "float size is: " << sizeof (float) * 8 << " bits" << std::endl;
// 	std::cout << "double size is: " << sizeof (double) * 8 << " bits" << std::endl;
// 	return (0);
// }
