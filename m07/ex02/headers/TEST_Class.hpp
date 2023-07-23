/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:07:00 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/23 14:00:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TEST_CLASS_HPP
#define TEST_CLASS_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

class TEST_Class
{
public:
	TEST_Class(void);
	~TEST_Class(void);
	TEST_Class(TEST_Class &instance);
	TEST_Class &operator=(TEST_Class &instance);
	void		setString(std::string string_to_set);
	void		setInteger(int int_to_set);
	void		setFloat(float float_to_set);
	void		setDouble(float double_to_set);
	std::string	getString(void);
	int			getInt(void);
	float		getFloat(void);
	double		getDouble(void);
	void		print(void);
private:
	std::string	_string;
	int			_integer;
	float		_float;
	double		_double;
};

std::ostream &operator<<(std::ostream &outStream, TEST_Class &instance);

#endif // TEST_CLASS_HPP
