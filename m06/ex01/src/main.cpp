/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:23:17 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/27 22:39:49 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main (void){
	Data * justSomeData;
	justSomeData = new Data;

	uintptr_t anOpaquePointer;
	anOpaquePointer = Serializer::serialize(justSomeData);

	/* note that we can't delete justSomeData through anOpaquePointer; */
	// delete anOpaquePointer;

	std::cout << "\n###### justSomeData data ######" << std::endl;
	std::cout << "address:\t" << justSomeData << std::endl;
	std::cout << "aString:\t" << justSomeData->aString << std::endl;
	std::cout << "anotherString:\t" << justSomeData->anotherString << std::endl;
	std::cout << "anUnsignedInt:\t" << justSomeData->anUnsignedInt << std::endl;
	std::cout << "aSingleChar:\t" << justSomeData->aSingleChar << std::endl;

	std::cout << "\n###### anOpaquePointer data ######" << std::endl;
	std::cout << "address:\t" << anOpaquePointer << std::endl;
	/* We can't derefence it either */
	// std::cout << "dereferecing:\t" << *anOpaquePointer << std::endl;
	/* We could however, access it's innards */
	std::cout << "anOpaquePointer first int:\t"<<*(unsigned int *)(anOpaquePointer) << std::endl;

	/* There is however a better usage of this crap */
	std::cout << "\n##### byteSerializer #####" << std::endl;
	unsigned char *byteptr = (unsigned char *)(anOpaquePointer);
	for (size_t i = 0; i < sizeof(Data); i++)
		std::cout << (unsigned int)(byteptr[i]) << "|";
	std::cout << std::endl;

	/* But seriously, if you're casting shit left and right, you're probably just fucking up the code */

	return 0;
}