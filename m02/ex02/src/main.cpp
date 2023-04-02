/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:37:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/01 18:40:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

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
