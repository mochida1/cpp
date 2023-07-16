/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:00:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/16 19:18:04 by hmochida         ###   ########.fr       */
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

}
