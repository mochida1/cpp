/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:40:46 by mochida           #+#    #+#             */
/*   Updated: 2023/11/20 22:52:48 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
int main (void){
	std::vector<int> vec;
	for ( int i = 0; i < 10; i++)
		vec.push_back(i);
	
	for (int i = 0; i < 10; i++)
		std::cout << *PmergeMe::getNthIterator(vec, i) << " ";
	std::cout << std::endl;
}
*/

int main (int argc, char *argv[]){
	std::cout << "program started with " << (argc - 1) << " numbers to sort!" << std::endl;
	if (argc == 1)
	{
		std::cerr << "Error: wrong input!" << std::endl;
	}

	// VECTOR
	{
		std::vector<int> vec;
		PmergeMe::argvToVector(vec, argc, argv);
		if (PmergeMe::isVerbose()){
			std::cout << "Vector to sort: ";
			PmergeMe::printVector(vec);
		}
		PmergeMe::sortVector(vec);

		if (PmergeMe::isVerbose()){
			PmergeMe::printVector(vec);
		}
		if (PmergeMe::isSorted(vec) == false){
			std::cerr << "VECTOR NOT SORTED!!!" << std::endl;
			return 1;
		} else {
			std::cout << "vector sorted successfully!" << std::endl;
		}
	}
	// LIST

	std::list<int> lst;
	PmergeMe::argvToList(lst, argc, argv);
	if (PmergeMe::isVerbose())
		PmergeMe::printList(lst);
	PmergeMe::sortList(lst);
	if (PmergeMe::isSorted(lst) == false){
		std::cerr << "LIST NOT SORTED!!!" << std::endl;
		return 1;
	} else {
		std::cout << "list sorted successfully!" << std::endl;
	}
		
	std::cout << "program end" << std::endl;
}

// 49566 15277 50685 82769 29118 95943 41310 54362 14346 96799
// 96852 52362 38374 31064 23392 72467 83493 57481 12021 18161