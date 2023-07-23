/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:00:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/22 16:31:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include <iostream>

int main (void)
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
