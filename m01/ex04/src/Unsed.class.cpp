/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unsed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:10:26 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 13:39:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unsed.class.hpp"

Unsed::Unsed(std::string file, std::string s1, std::string s2) : _outFileName(file + ".replace"), _inFileName(file), _s1(s1), _s2(s2) {
	return ;
}

Unsed::Unsed(void) {
	return ;
}

Unsed::~Unsed(void) {
	return ;
}

bool	Unsed::setOutFileName(std::string str) {
	this->_outFileName = str;
	if (this->_outFileName == str)
		return (true);
	return (false);
}

bool	Unsed::setInFileName(std::string filename) {
	this->_inFileName = filename;
	if (this->_inFileName == filename)
		return (true);
	return (false);
}

bool	Unsed::setS1(std::string str) {
	this->_s1 = str;
	if (this->_s1 == str)
		return (true);
	return (false);
}

bool	Unsed::setS2(std::string str) {
	this->_s2 = str;
	if (this->_s2 == str)
		return (true);
	return (false);
}

std::string const &Unsed::getOutFileName(void) {
	return (this->_outFileName);
}

std::string const &Unsed::getInFileName(void) {
	return (this->_inFileName);
}
