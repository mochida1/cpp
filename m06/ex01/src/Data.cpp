/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:05:43 by mochida           #+#    #+#             */
/*   Updated: 2023/07/01 19:48:00 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : aString("Hi, I'm String"), anotherString("Strings are strong"), anUnsignedInt(42), aSingleChar('d') {
	return ;
}

Data::~Data(void){
	return ;
}

Data::Data(std::string a, std::string b, unsigned int c, char d) : aString(a), anotherString(b), anUnsignedInt(c), aSingleChar(d){
	return ;
}

Data::Data(const Data & instance) {
	*this = instance;
	return ;
}

// copy operator constructor
Data & Data::operator=(const Data & instance) {
	this->aString = instance.aString;
	this->anotherString = instance.anotherString;
	this->anUnsignedInt = instance.anUnsignedInt;
	this->aSingleChar = instance.aSingleChar;
	return *this;
}
