/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:39 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/09 21:58:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void) {
	return ;
}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter & instance) {
	(void) (instance);
	return ;
}

// copy operator constructor
ScalarConverter & ScalarConverter::operator=(const ScalarConverter & instance) {
	(void) (instance);
	return *this;
}

// default destructor
ScalarConverter::~ScalarConverter(void) {
	return ;
}

bool ScalarConverter::convert(std::string argument) {
	if (!_checkArgument(argument))
		return false;
	return true;
}

bool _isWordLiteral(std::string argument) {
	std::string wordedLiterals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
		if (!argument.compare(wordedLiterals[i]))
			return true;
}

bool	ScalarConverter::_isAlpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

bool	ScalarConverter::_isDigit(char c){
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool	ScalarConverter::_isFloat(std::string argument) {
	int i = 0;
	if (&argument == NULL)
		return false;
	if (!_isDigit(argument[i]))
		return false;
	while (_isDigit(argument[i])) // integer part of the float
		i++;
	if (argument[i] != '.') // we've reached the . part of the float
	{
		if (argument[i] == 'f') // if the float has no fractional part, it is true; ie 42f
			return true;
		return false;
	}
	if (argument[i] && argument[i] == '.') // now we assert this is not a \0 and that it must be a '.'
		i++;
	if (!_isDigit(argument[i]))
		return false; // means the string comes as DD.C
	while (_isDigit(argument[i]))
		i++;
	if (argument[i] && argument[i] == 'f' && argument[i+1] == '\0')
		return true;
	return false;
}

bool	ScalarConverter::_isDouble(std::string argument) {
}

bool	ScalarConverter::_isInt(std::string argument) {
}

/*
	Examples of char literals: ’c’, ’a’, ...
	Examples of int literals: 0, -42, 42...
	Examples of float literals: 0.0f, -4.2f, 4.2f...-inff, +inff and nanf.
	Examples of double literals: 0.0, -4.2, 4.2...-inf, +inf and nan.
*/
int ScalarConverter::_checkArgument(std::string argument) {
	if ( _isFloat("42.042f"))
		return true;
	return false;

	if ( _isWordLiteral(argument) )
		return true;
	if ( argument.length() == 1 && _isAlpha(argument[0]) )
		return true;

	return false;
}

bool		ScalarConverter::tests(void){

	std::cout << "-------------TESTING [_isFloat]-------------" << std::endl;
	assert(_isFloat("42.042f") == true);
	assert(_isFloat("0.042f") == true);
	assert(_isFloat("42f") == true);
	assert(_isFloat("0f") == true);
	assert(_isFloat("") == false);
	assert(_isFloat("f") == false);
	assert(_isFloat("123") == false);
	assert(_isFloat("123.123ff") == false);
	assert(_isFloat(".123f") == false);
	assert(_isFloat(".f") == false);
	assert(_isFloat("1.f") == false);
	assert(_isFloat("123.123f123") == false);

}
