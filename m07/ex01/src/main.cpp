/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:25:03 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/09 18:45:21 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Fixed.hpp"

void test_c_string(void)
{
	std::cout << "\n\t### testing C_STRING" << std::endl;

	std::string string_a = std::string("I am a string");
	std::cout << "<<<<<" << std::endl;
	std::cout << "String Addres:\t"<< &string_a << std::endl;
	std::cout << "String Value:\t"<< string_a << std::endl;
	std::cout << ">>>>>" << std::endl;
	iter(string_a.c_str(), string_a.length(), print_member);

	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
}

void test_int(void)
{
	std::cout << "\n\t### testing INT" << std::endl;

	int *intArray = new int[42];
	for (int i = 41; i >= 0; i--)
		intArray[41 - i] = i;
	std::cout << "---------------------------" << std::endl;
	iter (intArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	iter (intArray, 42, increment);
	iter (intArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	iter (intArray, 42, square);
	iter (intArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	delete [] intArray;

	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
}

void test_float(void)
{
	std::cout << "\n\t### testing FLOAT" << std::endl;

	float *floatArray = new float[42];
	for (int i = 41; i >= 0; i--)
		floatArray[41 - i] = ( 1 + (1/((float)(i)+1)) )* (i%2 == 0 ? 1 : -1);
	std::cout << "---------------------------" << std::endl;
	iter (floatArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	iter (floatArray, 42, increment);
	iter (floatArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	iter (floatArray, 42, square);
	iter (floatArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	delete [] floatArray;

	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
}

void test_charptr(void)
{
	std::cout << "\n\t### testing CHAR PTR" << std::endl;

	char charptr[] = "abcdefgh123456789";
	std::cout << "---------------------------" << std::endl;
	iter (charptr, sizeof(charptr), print_member);
	std::cout << "---------------------------" << std::endl;
	iter (charptr, sizeof(charptr), increment);
	iter (charptr, sizeof(charptr), print_member);
	std::cout << "---------------------------" << std::endl;
	iter (charptr, sizeof(charptr), square);
	iter (charptr, sizeof(charptr), print_member);
	std::cout << "---------------------------" << std::endl;

	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
}

void test_fixed()
{
	std::cout << "\n\t### testing FIXED" << std::endl;

	Fixed *fixedArray = new Fixed[42];
	for (int i = 41; i >= 0; i--)
		fixedArray[41 - i] = ( 1 + (1/((float)(i)+1)) )* (i%2 == 0 ? 1 : -1);
	std::cout << "---------------------------" << std::endl;
	iter (fixedArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	iter (fixedArray, 42, increment);
	iter (fixedArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	iter (fixedArray, 42, square);
	iter (fixedArray, 42, print_member);
	std::cout << "---------------------------" << std::endl;
	delete [] fixedArray;

	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
}

int main (void)
{
	test_c_string();
	test_int();
	test_float();
	test_charptr();
	test_fixed();
}
