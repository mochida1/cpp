/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:37:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/22 21:22:38 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main (void)
{
	Fixed defConstr;
	Fixed argConstr(-42);
	Fixed copyConstr(defConstr);
	Fixed opConstr;

	opConstr = argConstr;

	std::cout << "def:  " << defConstr.getRawBits() << std::endl;
	std::cout << "arg:  " << argConstr.getRawBits() << std::endl;
	std::cout << "copy: " << copyConstr.getRawBits() << std::endl;
	std::cout << "op:   " << opConstr.getRawBits() << std::endl;

	defConstr.printFixedMin();
	defConstr.printFixedMax();
	defConstr.printOne();
	argConstr.printInt();
	return (0);
}
