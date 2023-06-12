/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:39 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/11 21:26:20 by hmochida         ###   ########.fr       */
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
	std::string str = _trim(argument);
	int dataType = _checkArgument(str);
	switch (dataType)
	{
	case DATA_TYPE_ERROR:
		std::cerr << "ERROR[convert]: Parser didn't recognize input as valid!" << std::endl;
		return false;
		break;
	case DATA_TYPE_DOUBLE:
		std::cout << "DATA_TYPE is DOUBLE!" << std::endl;
		_convertFromDouble(argument);
		break;
	case DATA_TYPE_FLOAT:
		std::cout << "DATA_TYPE is FLOAT" << std::endl;
		break;
	case DATA_TYPE_INT:
		std::cout << "DATA_TYPE is INT" << std::endl;
		break;
	case DATA_TYPE_CHAR:
		std::cout << "DATA_TYPE is CHAR!" << std::endl;
		break;
	default:
		std::cerr << "you IS hackerman" << std::endl;
		break;
	}
	return true;
}

std::string ScalarConverter::_trim(const std::string& str) {
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	size_t end = str.find_last_not_of(" \t\n\r\f\v");

	if (start == std::string::npos || end == std::string::npos)
		return "";

	return str.substr(start, end - start + 1);
}

bool ScalarConverter::_isWordLiteral(std::string argument) {
	const std::string wordedLiterals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
		if (!argument.compare(wordedLiterals[i]))
			return true;
	return false;
}

bool ScalarConverter::_isFloatWordLiteral(std::string argument) {
	const std::string wordedFloatLiterals[] = {"-inff", "+inff", "nanf"};
	int arraySize = sizeof(wordedFloatLiterals) / sizeof(wordedFloatLiterals[0]);

	for (int i = 0; i < arraySize; i++)
		if (!argument.compare(wordedFloatLiterals[i]))
			return true;
	return false;
}

bool ScalarConverter::_isDoubleWordLiteral(std::string argument) {
	const	std::string wordedDoubleLiterals[] = {"-inf", "+inf", "nan"};
	int		arraySize = sizeof(wordedDoubleLiterals) / sizeof(wordedDoubleLiterals[0]);

	for (int i = 0; i < arraySize; i++)
		if (!argument.compare(wordedDoubleLiterals[i]))
			return true;
	return false;
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

	if (argument.compare("") == 0)
		return false;
	if (_isFloatWordLiteral(argument))
		return true;
	if (argument[i] == '-' || argument[i] == '+') // checks wheter there's a signal
		i++;
	if (!_isDigit(argument[i]))
		return false;
	while (_isDigit(argument[i])) // integer part of the float
		i++;
	if (argument[i] != '.') // we've reached the . part of the float
	{
		if (argument[i] == 'f') // if the float has no fractional part, it is true; ie 42f
		{
			std::istringstream iss(argument);
			double	doubleValue;
			iss >> doubleValue;
			if (doubleValue > std::numeric_limits<int>::max() || doubleValue < std::numeric_limits<int>::min())
				return false;
			return true;
		}
		return false;
	}
	if (argument[i] && argument[i] == '.') // now we assert this is not a \0 and that it must be a '.'
		i++;
	if (!_isDigit(argument[i]))
		return false; // means the string comes as DD.C
	while (_isDigit(argument[i]))
		i++;
	if (argument[i] && argument[i] == 'f' && argument[i+1] == '\0')
	{
		std::istringstream iss(argument);
		double	doubleValue;
		iss >> doubleValue;
		if (doubleValue < 0) // the sign bit does not affects or limits
			doubleValue *= -1;
		if ( (doubleValue > std::numeric_limits<float>::max() || doubleValue < std::numeric_limits<float>::min()) && doubleValue != 0) // edge case of 0.0f IS a valid float.
			return false;
		return true;
	}
	return false;
}

bool	ScalarConverter::_isDouble(std::string argument) {
	int i = 0;
	if (argument.compare("") == 0)
		return false;
	if (_isDoubleWordLiteral(argument))
		return true;
	if (argument[i] == '-' || argument[i] == '+') // checks wheter there's a signal
		i++;
	if (!_isDigit(argument[i]))
		return false;
	while (_isDigit(argument[i])) // integer part of the float
		i++;
	if (argument[i] != '.') // we've reached the . part of the float
	{
		if (argument[i] == '\0') // if the double has no fractional part, it is true; ie 42
			return true;
		return false;
	}
	if (argument[i] && argument[i] == '.') // now we assert this is not a \0 and that it must be a '.'
		i++;
	if (!_isDigit(argument[i]))
		return false; // means the string comes as DD.C
	while (_isDigit(argument[i]))
		i++;
	while (argument[i] && std::isspace(argument[i]))
		i++;
	if (!argument[i])
		return true;
	return false;

}

bool	ScalarConverter::_isInt(std::string argument) {
	int	i = 0;
	if (argument.length() == 0)
		return false;
	if (argument[0] == '-' || argument[0] == '+')
		i++;
	if (argument[i] == '\0')
		return false;
	while (argument[i])
	{
		if (_isDigit(argument[i]))
			i++;
		else
			return false;
	}
	std::istringstream iss(argument);

	double	doubleValue;
	iss >> doubleValue;
	if (doubleValue > std::numeric_limits<int>::max() || doubleValue < std::numeric_limits<int>::min())
		return false;
	return true;
}

bool ScalarConverter::_isChar(std::string argument) {
	if (argument.length() != 1)
		return false;
	if (std::isprint(argument[0]) && argument[1] == '\0')
		return true;
	return false;
}

/*
	Examples of char literals: ’c’, ’a’, ...
	Examples of int literals: 0, -42, 42...
	Examples of float literals: 0.0f, -4.2f, 4.2f...-inff, +inff and nanf.
	Examples of double literals: 0.0, -4.2, 4.2...-inf, +inf and nan.
*/
int ScalarConverter::_checkArgument(std::string argument) {
	if (_isChar(argument))
		return DATA_TYPE_CHAR;
	else if (_isInt(argument))
		return DATA_TYPE_INT;
	else if (_isFloat(argument))
		return DATA_TYPE_FLOAT;
	else if (_isDouble(argument))
		return DATA_TYPE_DOUBLE;
	else
		return DATA_TYPE_ERROR;
}


bool		ScalarConverter::tests(void){
	_printMaxValues();
	std::cout << "\n-------------TESTING [_trim]----------------" << std::endl;
	assert(_trim("   spaces     and stuff \t\v").compare("spaces     and stuff") == 0);

	std::cout << "-------------TESTING [_isFloat]-------------" << std::endl;
	assert(_isFloat("-inff") == true);
	assert(_isFloat("+inff") == true);
	assert(_isFloat("nanf") == true);
	assert(_isFloat("42.042f") == true);
	assert(_isFloat("0.042f") == true);
	assert(_isFloat("42f") == true);
	assert(_isFloat("0f") == true);
	assert(_isFloat("0.0f") == true);
	assert(_isFloat("-42.042f") == true);
	assert(_isFloat("-0.042f") == true);
	assert(_isFloat("-42f") == true);
	assert(_isFloat("-0f") == true);
	assert(_isFloat("") == false);
	assert(_isFloat("f") == false);
	assert(_isFloat("123") == false);
	assert(_isFloat("123.123") == false);
	assert(_isFloat("123.123ff") == false);
	assert(_isFloat(".123f") == false);
	assert(_isFloat(".f") == false);
	assert(_isFloat("1.f") == false);
	assert(_isFloat("123.123f123") == false);
	assert(_isFloat("123.f") == false);
	assert(_isFloat("-inf") == false);
	assert(_isFloat("+inf") == false);
	assert(_isFloat("nan") == false);
	assert(_isFloat("a") == false);
	assert(_isFloat("z") == false);
	assert(_isFloat("A") == false);
	assert(_isFloat("Z") == false);

	std::cout << "-------------TESTING [_isDouble]------------" << std::endl;
	assert(_isDouble("123") == true);
	assert(_isDouble("42.042") == true);
	assert(_isDouble("0.042") == true);
	assert(_isDouble("42") == true);
	assert(_isDouble("0") == true);
	assert(_isDouble("0.0") == true);
	assert(_isDouble("-42.042") == true);
	assert(_isDouble("-0.042") == true);
	assert(_isDouble("-42") == true);
	assert(_isDouble("-0") == true);
	assert(_isDouble("42.042f") == false);
	assert(_isDouble("0.042f") == false);
	assert(_isDouble("42f") == false);
	assert(_isDouble("0f") == false);
	assert(_isDouble("-42.042f") == false);
	assert(_isDouble("-0.042f") == false);
	assert(_isDouble("-42f") == false);
	assert(_isDouble("-0f") == false);
	assert(_isDouble("") == false);
	assert(_isDouble("f") == false);
	assert(_isDouble("123.123ff") == false);
	assert(_isDouble(".123f") == false);
	assert(_isDouble(".f") == false);
	assert(_isDouble("1.f") == false);
	assert(_isDouble("123.123f123") == false);
	assert(_isDouble("123.f") == false);
	assert(_isDouble("a") == false);
	assert(_isDouble("z") == false);
	assert(_isDouble("A") == false);
	assert(_isDouble("Z") == false);

	std::cout << "-------------TESTING [_isInt]---------------" << std::endl;
	assert(_isInt("123") == true);
	assert(_isInt("42") == true);
	assert(_isInt("-42") == true);
	assert(_isInt("-0") == true);
	assert(_isInt("0") == true);
	assert(_isInt("0.0") == false);
	assert(_isInt("42.042") == false);
	assert(_isInt("0.042") == false);
	assert(_isInt("-42.042") == false);
	assert(_isInt("-0.042") == false);
	assert(_isInt("42.042f") == false);
	assert(_isInt("0.042f") == false);
	assert(_isInt("42f") == false);
	assert(_isInt("0f") == false);
	assert(_isInt("-42.042f") == false);
	assert(_isInt("-0.042f") == false);
	assert(_isInt("-42f") == false);
	assert(_isInt("-0f") == false);
	assert(_isInt("") == false);
	assert(_isInt("f") == false);
	assert(_isInt("123.123ff") == false);
	assert(_isInt(".123f") == false);
	assert(_isInt(".f") == false);
	assert(_isInt("1.f") == false);
	assert(_isInt("123.123f123") == false);
	assert(_isInt("123.f") == false);
	assert(_isInt("a") == false);
	assert(_isInt("z") == false);
	assert(_isInt("A") == false);
	assert(_isInt("Z") == false);

	std::cout << "-------------TESTING [_isChar]--------------" << std::endl;
	assert(_isChar("a") == true);
	assert(_isChar("z") == true);
	assert(_isChar("A") == true);
	assert(_isChar("f") == true);
	assert(_isChar("Z") == true);
	assert(_isChar("0") == true);
	assert(_isChar("123") == false);
	assert(_isChar("42") == false);
	assert(_isChar("-42") == false);
	assert(_isChar("-0") == false);
	assert(_isChar("0.0") == false);
	assert(_isChar("42.042") == false);
	assert(_isChar("0.042") == false);
	assert(_isChar("-42.042") == false);
	assert(_isChar("-0.042") == false);
	assert(_isChar("42.042f") == false);
	assert(_isChar("0.042f") == false);
	assert(_isChar("42f") == false);
	assert(_isChar("0f") == false);
	assert(_isChar("-42.042f") == false);
	assert(_isChar("-0.042f") == false);
	assert(_isChar("-42f") == false);
	assert(_isChar("-0f") == false);
	assert(_isChar("") == false);
	assert(_isChar("123.123ff") == false);
	assert(_isChar(".123f") == false);
	assert(_isChar(".f") == false);
	assert(_isChar("1.f") == false);
	assert(_isChar("123.123f123") == false);
	assert(_isChar("123.f") == false);

	return true;
}

void	ScalarConverter::_setToLiterals(std::string argument, double &doubleValue, float &floatValue){
	if (argument.compare("nan") == 0)
	{
		doubleValue = std::numeric_limits<double>::quiet_NaN();
		floatValue = std::numeric_limits<float>::quiet_NaN();
	}
	else if (argument.compare("+inf") == 0)
	{
		doubleValue = std::numeric_limits<double>::infinity();
		floatValue = std::numeric_limits<float>::infinity();
	}
	else if (argument.compare("-inf") == 0)
	{
		doubleValue = std::numeric_limits<double>::infinity() * -1;
		floatValue = std::numeric_limits<float>::infinity() * -1;
	}
	else
		return ;
}

std::string ScalarConverter::_getFloatLiteralString(float floatvalue){
	if (std::isnan(floatvalue))
		return "nanf";
	else if (floatvalue == std::numeric_limits<float>::infinity())
		return "inff";
	else
		return "-inff";
}

std::string	ScalarConverter::_charValueToPrint(char c){
	std::string ret("");
	if (std::isprint(c))
	{
		ret += '\'';
		ret += c;
		ret += '\'';
	}
	else
		ret = "Non displayable";
	return ret;
}

std::string ScalarConverter::_printZeroIfNeeded(float floatValue)
{
	int temp = static_cast<int>(floatValue);
	if (floatValue - temp == 0)
		return ".0";
	return "";
}

std::string ScalarConverter::_printZeroIfNeeded(double doubleValue){
	int temp = static_cast<int>(doubleValue);
	if (doubleValue - temp == 0)
		return ".0";
	return "";
}

void	ScalarConverter::_convertFromDouble(std::string argument){
	std::istringstream iss(argument);
	float	floatValue = 0;
	double	doubleValue = 0;
	int		intValue = 0;
	char	charValue = 0;
	double	doubleValueTemp = 0;
	if (_isWordLiteral(argument))
		_setToLiterals(argument, doubleValue, floatValue);
	else
	{
		iss >> doubleValue;
		floatValue = static_cast<float>(doubleValue);
	}
	// infinity is greater than a really fucking humongous number. No warnings should be sent;
	if (doubleValue >= std::numeric_limits<double>::max() && doubleValue != std::numeric_limits<double>::infinity())
			std::cout << "WARNING! You used a LOT of numbers, double may have been overflown!" << std::endl;
	intValue = static_cast<int>(doubleValue);
	charValue = static_cast<char>(doubleValue);
	if (_isWordLiteral(argument))
	{
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		std::cout << "float:\t" << _getFloatLiteralString(floatValue) << std::endl;
		std::cout << "double:\t" << doubleValue << std::endl;
		return ;
	}
	if (std::floor(doubleValue) > 127 || std::floor(doubleValue) < -128)
		std::cout << "char:\t impossible" << std::endl;
	else
		std::cout << "char:\t" << _charValueToPrint(charValue) << std::endl;
	if (std::floor(doubleValue) > std::numeric_limits<int>::max() || std::floor(doubleValue) < std::numeric_limits<int>::min())
		std::cout << "int:\t impossible" << std::endl;
	else
		std::cout << "int:\t" << intValue << std::endl;
	if (doubleValue < 0) // the sign bit does not affects or limits
		doubleValueTemp = doubleValue* -1;
	if ( (doubleValueTemp > std::numeric_limits<float>::max() || doubleValueTemp < std::numeric_limits<float>::min()) && doubleValue != 0)
		std::cout << "float:\timpossible"<< std::endl;
	else
		std::cout << "float:\t" << floatValue << _printZeroIfNeeded(floatValue) << 'f' << std::endl;
	std::cout << "double:\t" << doubleValue << _printZeroIfNeeded(doubleValue) << std::endl;
}

void	ScalarConverter::_convertFromFloat(std::string argument){
	std::istringstream iss(argument);
	float	floatValue;
	// double	doubleValue;
	// int		intValue;
	// char	charValue;
	iss >> floatValue;
	if (floatValue > std::numeric_limits<int>::max())
		std::cout << "SUFHDUGDFGHXFDHXFDIHXFIHFHIXFDHXHXFGH" << std::endl;
}

void	ScalarConverter::_convertFromInt(std::string argument){
	(void)(argument);
}

void	ScalarConverter::_convertFromChar(std::string argument){
	(void)(argument);
}

void ScalarConverter::_printMaxValues(void){
	std::cout << "\n## Printing VARIABLES WITH ALL BITS ON ##" << std::endl;
	_printMaxDouble();
	_printMaxFloat();
	_printMaxInt();
	_printMaxChar();
}

void ScalarConverter::_printMaxDouble(void){
	unsigned long long valueAsInt = 0xffffffffffffffff;
	bool	bitVal;
	double	val = *reinterpret_cast<double*>(&valueAsInt);
	double	max = std::numeric_limits<double>::max();
	size_t	lSize = sizeof(val) * 8;
	std::cout << "MAX DOUBLE: size["<< lSize <<"] Value:[" << val << "]  INT value:[" << valueAsInt <<"] max valid value:[" << max << "]" << std::endl;
	for (int i = lSize - 1; i >= 0; i--)
	{
		if ( (i%8 == 0) && i != 0 )
			std::cout << ' ';
		bitVal = (valueAsInt & (1ULL << i));
		std::cout << bitVal;
	}
	std::cout << std::endl;
	valueAsInt = *reinterpret_cast<unsigned long long*>(&max);
	std::cout << "MAX valid DOUBLE: size["<< lSize <<"] Value:[" << max << "]  INT value:[" << valueAsInt <<"]" << std::endl;
	for (int i = lSize - 1; i >= 0; i--)
	{
		if ( (i%8 == 0) && i != 0 )
			std::cout << ' ';
		bitVal = (valueAsInt & (1ULL << i));
		std::cout << bitVal;
	}
	std::cout << std::endl;
	return ;
}

void ScalarConverter::_printMaxFloat(void){
	unsigned int valueAsInt = 0xffffffff;
	bool	bitVal;
	float	val = *reinterpret_cast<float*>(&valueAsInt);
	size_t	lSize = sizeof(val) * 8;
	std::cout << "MAX float: size["<< lSize <<"] Value:[" << val << "]  INT value:[" << valueAsInt <<"]" << std::endl;
	for (int i = lSize - 1; i >= 0; i--)
	{
		if ( (i%8 == 0) && i != 0 )
			std::cout << ' ';
		bitVal = (valueAsInt & (1 << i));
		std::cout << bitVal;
	}
	std::cout << std::endl;
	return ;
}

void ScalarConverter::_printMaxInt(void){
	int	printme = 0;
	size_t	lSize = sizeof(printme) * 8;
	bool	bitVal;
	for (size_t i = 0; i < lSize; i++)
		printme += (1 << i);
	std::cout << "MAX Int: size["<< lSize <<"] [" << printme << "]" << std::endl;
	for (size_t i = 0; i < lSize; i++)
	{
		if ( (i%8 == 0) && i != 0 )
			std::cout << ' ';
		bitVal = (printme & (1 << i));
		std::cout << bitVal;
	}
	std::cout << std::endl;
	return ;
}

void ScalarConverter::_printMaxChar(void){
	char	printme = 0;
	size_t	lSize = sizeof(printme) * 8;
	bool	bitVal;
	for (size_t i = 0; i < lSize; i++)
		printme += (1 << i);
	std::cout << "MAX Char: size["<< lSize <<"] [" << (int)(printme) << "]" << std::endl;
	for (size_t i = 0; i < lSize; i++)
	{
		if ( (i%8 == 0) && i != 0 )
			std::cout << ' ';
		bitVal = (printme & (1 << i));
		std::cout << bitVal;
	}
	std::cout << std::endl;
	return ;
}
