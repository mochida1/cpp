/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:46 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/11 21:19:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef SCALARCONVERTER_HPP
#  define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>

#define DATA_TYPE_ERROR		0
#define DATA_TYPE_CHAR		1
#define DATA_TYPE_INT		2
#define DATA_TYPE_FLOAT		3
#define DATA_TYPE_DOUBLE	4

class ScalarConverter{
public:
	static bool			convert(std::string argument);
	static bool			tests();
protected:
private:
	// OCF -------------------- those are private to simulate a "static class", wich does not exists in CPP
	// note that Orthodox Cannonical Form is here only for formality.
	ScalarConverter(void); // Default constructor
	ScalarConverter(const ScalarConverter & instance); // copy constructor
	ScalarConverter & operator=(const ScalarConverter & instance); // copy operator constructor
	~ScalarConverter(void);
	// -------------------- OCF
	static int	_checkArgument(std::string argument);
	static std::string	_trim(const std::string& str);
	static bool	_isAlpha(char c);
	static bool	_isWordLiteral(std::string argument);
	static bool _isFloatWordLiteral(std::string argument);
	static bool _isDoubleWordLiteral(std::string argument);
	static bool	_isFloat(std::string argument);
	static bool	_isDouble(std::string argument);
	static bool	_isInt(std::string argument);
	static bool	_isChar(std::string argument);
	static bool	_isDigit(char c);
	static void	_convertFromDouble(std::string argument);
	static void	_convertFromFloat(std::string argument);
	static void	_convertFromInt(std::string argument);
	static void	_convertFromChar(std::string argument);
	static void	_setToLiterals(std::string argument, double &doubleValue, float &floatValue);
	static std::string _getFloatLiteralString(float floatvalue);
	static std::string	_charValueToPrint(char c);
	static std::string _printZeroIfNeeded(float floatValue);
	static std::string _printZeroIfNeeded(double doubleValue);

	// DEBUG
	static void	_printMaxValues(void);
	static void	_printMaxDouble(void);
	static void	_printMaxFloat(void);
	static void	_printMaxInt(void);
	static void	_printMaxChar(void);
};

#endif // SCALARCONVERTER_HPP
