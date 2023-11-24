/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:40:46 by mochida           #+#    #+#             */
/*   Updated: 2023/11/23 22:08:41 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

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
	if (PmergeMe::isVerbose())
		std::cout << "program started with " << (argc - 1) << " numbers to sort!" << std::endl;
	if (argc == 1)
	{
		std::cerr << "Error: wrong input!" << std::endl;
	}
	std::clock_t start;
	std::clock_t vecEnd;
	std::clock_t lstEnd;

	// VECTOR
	{
		std::vector<int> vec;
		PmergeMe::argvToVector(vec, argc, argv);

		std::cout << "Before: ";
		PmergeMe::printVector(vec);
		start = clock();
		PmergeMe::sortVector(vec);
		vecEnd = clock() - start;
		std::cout << "After:  ";
		PmergeMe::printVector(vec);

		if (PmergeMe::isVerbose()){
			PmergeMe::printVector(vec);
		}
		if (PmergeMe::isSorted(vec) == false){
			if (PmergeMe::isVerbose())
				std::cerr << "VECTOR NOT SORTED!!!" << std::endl;
			return 1;
		} else {
			if (PmergeMe::isVerbose())
				std::cout << "vector sorted successfully!" << std::endl;
		}
	}

	// LIST
	{
		std::list<int> lst;
		PmergeMe::argvToList(lst, argc, argv);
		start = clock();
		PmergeMe::sortList(lst);
		lstEnd = clock() - start;
		if (PmergeMe::isSorted(lst) == false){
			if (PmergeMe::isVerbose())
				std::cerr << "LIST NOT SORTED!!!" << std::endl;
			return 1;
		} else {
			if (PmergeMe::isVerbose())
				std::cout << "list sorted successfully!" << std::endl;
		}
	}

	if (0){
		clock_t sortListEnd;
		std::list<int> sortList;
		PmergeMe::argvToList(sortList, argc, argv);
		start = clock();
		sortList.sort();
		sortListEnd = clock() - start;
		std::cout << "Time to sort [" << argc - 1 << "] using LIST sort() method : " << (float)sortListEnd/CLOCKS_PER_SEC << " seconds" << std::endl;
	}

	// couts
	std::cout << "Time to sort [" << argc - 1 << "] using VECTOR: " << (float)vecEnd/CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "Time to sort [" << argc - 1 << "] using LIST  : " << (float)lstEnd/CLOCKS_PER_SEC << " seconds" << std::endl;


	if (PmergeMe::isVerbose())
		std::cout << "program end" << std::endl;
}

// 49566 15277 50685 82769 29118 95943 41310 54362 14346 96799
// 96852 52362 38374 31064 23392 72467 83493 57481 12021 18161