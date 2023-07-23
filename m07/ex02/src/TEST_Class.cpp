/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:06:43 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/23 14:40:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TEST_Class.hpp"

static double random_double(void);
static float random_float(void);
static int random_int(int min, int max);
static std::string gen_random_string(const int len);

TEST_Class::TEST_Class(void) : _string( gen_random_string(random_int(5, 15)) ), _integer(rand()), _float(random_float()), _double(random_double()) {
	srand(time(0) + rand());
	return ;
}

TEST_Class::~TEST_Class(void){
		return ;
}

TEST_Class::TEST_Class(TEST_Class &instance) {
	*this = instance;
	return ;
}

TEST_Class & TEST_Class::operator=(TEST_Class &instance) {
	this->_string = instance.getString();
	this->_integer = instance.getInt();
	this->_float = instance.getFloat();
	this->_double = instance.getDouble();
	return *this;
}

void		TEST_Class::setString(std::string string_to_set) {
	this->_string = string_to_set;
	return ;
}

void		TEST_Class::setInteger(int int_to_set) {
	this->_integer = int_to_set;
	return ;
}

void		TEST_Class::setFloat(float float_to_set) {
	this->_float = float_to_set;
	return ;
}

void		TEST_Class::setDouble(float double_to_set) {
	this->_double = double_to_set;
	return ;
}

std::string	TEST_Class::getString(void) {
	return this->_string;
}

int			TEST_Class::getInt(void) {
	return this->_integer;
}

float		TEST_Class::getFloat(void) {
	return this->_float;
}

double		TEST_Class::getDouble(void) {
	return this->_double;
}

void		TEST_Class::print(void) {
	std::cout << "String = [" << this->getString() << "]  ";
	std::cout << "Int = [" << this->getInt() << "]  ";
	std::cout << "Float = [" << this->getFloat() << "]  ";
	std::cout << "Double = [" << this->getDouble() << "]  ";
}

std::ostream &operator<<(std::ostream &outStream, TEST_Class &instance)
{
	instance.print();
	return outStream;
}

static std::string gen_random_string(const int len)
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;

	tmp_s.reserve(len);
	srand(rand());
	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}

//generates a random_int varying from <min> to <max>
static int random_int(int min, int max)
{
	int delta;
	int ret;

	srand(rand());
	delta = max - min;
	ret = (rand()%delta) + min;
	return ret;
}

static float random_float(void)
{
	srand(rand());
	return (float)(rand()) / (float)(rand());
}

static double random_double(void)
{
	srand(rand());
	return (double)(rand()) / (double)(rand()%7851);
}
