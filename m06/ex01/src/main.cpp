/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:23:17 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/01 19:49:55 by hmochida         ###   ########.fr       */
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

	/* Now we delete the data because valgrind */
	delete justSomeData;

	/* But seriously, if you're casting shit left and right, you're probably just fucking up the code */

	return 0;
}
