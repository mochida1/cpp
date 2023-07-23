/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:00:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/23 14:44:04 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include "TEST_Class.hpp"
#include <iostream>

void TEST_intArray(void)
{
	unsigned int MAX = 52;
	Array<int>intArray(MAX);
	std::cout << "intArray.size(): "<< intArray.size() << std::endl;
	for (unsigned int i = 0; i < MAX; i++)
		intArray[i] = (int)(i);
	std::cout << "intArray[0]:" << intArray[0] << " intArray[MAX-1]: " << intArray[MAX-1] << std::endl;
	// intArray[52] = 1; // this throws an exception as inteded;


	// COPY OPERATOR
	Array<int>intArrayCopy(intArray);
	std::cout << "intArrayCopy: [ ";
	for (unsigned int i = 0; i < MAX; i++)
		std::cout << intArrayCopy[i] << " ";
	std::cout << " ]" << std::endl;

	std::cout << "intArrayCopy reassigned: [ ";
	for (unsigned int i = 0; i < MAX; i++)
	{
		intArrayCopy[i] = (int)(MAX - i);
		std::cout << intArrayCopy[i] << " ";
	}
	std::cout << " ]" << std::endl;

	std::cout << "intArray: [ ";
	for (unsigned int i = 0; i < MAX; i++)
		std::cout << intArray[i] << " ";
	std::cout << " ]" << std::endl;

	// COPY ASSIGNMENT OPERATOR
	std::cout << "\nCOPY ASSIGNMENT OPERATOR [intArrayCopy = intArray]" << std::endl;
	intArrayCopy = intArray;

	std::cout << "intArrayCopy reassigned: [ ";
	for (unsigned int i = 0; i < MAX; i++)
		std::cout << intArrayCopy[i] << " ";
	std::cout << " ]" << std::endl;

	std::cout << "intArray: [ ";
	for (unsigned int i = 0; i < MAX; i++)
		std::cout << intArray[i] << " ";
	std::cout << " ]" << std::endl;
}

void TEST_TEST_Class(void)
{
	TEST_Class teste;
	std::cout << "teste.getString = [" << teste.getString() << "]" << std::endl;
	std::cout << "teste.getInt = [" << teste.getInt() << "]" << std::endl;
	std::cout << "teste.getFloat = [" << teste.getFloat() << "]" << std::endl;
	std::cout << "teste.getDobule = [" << teste.getDouble() << "]" << std::endl;

	teste.print();
	std::cout << std::endl;

	TEST_Class testeOStream;
	std::cout << "OStream: " << testeOStream << std::endl;
}

void TEST_ClassArray(void)
{
	Array<TEST_Class>testArray00(52);

	std::cout << "\n<<<<<<<<<<<       testArray00(52)" << std::endl;
	for ( int i = 0; i < 52; i++)
		std::cout << "[" << i << "]" << " " << testArray00[i] << std::endl;

	std::cout << "\n<<<<<<<<<<<       testArray01(10)" << std::endl;
	Array<TEST_Class>testArray01(10);
	for ( int i = 0; i < 10; i++)
		std::cout << "[" << i << "]" << " " << testArray01[i] << std::endl;

	std::cout << "\n######## testArray01 = testArray00 #########" << std::endl;
	testArray01 = testArray00;
	for ( int i = 0; i < 52; i++)
		std::cout << "[" << i << "]" << " " << testArray01[i] << std::endl;
}

int main (void)
{
	TEST_intArray();
	TEST_TEST_Class();
	TEST_ClassArray();
}
