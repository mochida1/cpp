/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:08:08 by mochida           #+#    #+#             */
/*   Updated: 2023/11/20 22:54:53 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::isVerbose(void){
	return PmergeMe::_verbose;
}

int PmergeMe::getSizeThreshold(void){
	return PmergeMe::_sizeThreshold;
}

// VECTOR ----------------------------------

void PmergeMe::argvToVector(std::vector<int> & vector, int argc, char *argv[]){
	for (int i = 1; i < argc; i++)
		vector.push_back(std::atoi(argv[i]));
}

void PmergeMe::printVector(std::vector<int> vector){
	int i = 0;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
		i++;
	}
	std::cout << std::endl;
	std::cout << "vector entries: " << i << std::endl;
}

std::vector<int>::iterator PmergeMe::getNthIterator(std::vector<int> & pVector, int index){
	std::vector<int>::iterator it = pVector.begin();
	std::advance(it, index);
	return it;
}

bool PmergeMe::isSorted(std::vector<int> pVector){
	for (int i = 0; i != (int)(pVector.size() - 1); i++)
	{
		if (pVector[i] > pVector[i + 1])
			return false;
	}
	return true;
}


void PmergeMe::merge(std::vector<int> & pVector, int startIndex, int middleIndex, int lastIndex) {
	// builds the left and right side of the vector
	int leftLimit = middleIndex - startIndex + 1;
	int rightLimit = lastIndex - middleIndex; 
	std::vector<int> vecLeft;
	std::vector<int> vecRight;

	for (int i = 0; i < leftLimit; i++)
	{
		vecLeft.push_back(pVector[startIndex + i]);
	}
	for (int i = 0; i < rightLimit; i++)
	{
		vecRight.push_back(pVector[middleIndex + 1 + i]);
	}

	if (PmergeMe::isVerbose()){
		std::cout << "Vector left ------------" << std::endl;
		std::cout << "vecLeft.size(): " << vecLeft.size() << std::endl;
		PmergeMe::printVector(vecLeft);
		std::cout << "-------------------------" << std::endl;
		std::cout << "Vector right ------------" << std::endl;
		std::cout << "vecRight.size(): " << vecRight.size() << std::endl;
		PmergeMe::printVector(vecRight);
		std::cout << "-------------------------" << std::endl;
		std::cout << "Merging startIndex:[" << startIndex << "] lastIndex:[" << lastIndex << "] midIndex:[" << middleIndex << "] delta:[" << lastIndex - startIndex << "]" << std::endl;
	}
	int indexLeft = 0;
	int indexRight = 0;
	int i = startIndex;
	while (indexLeft < (int)(vecLeft.size()) && indexRight < (int)(vecRight.size())){
		if (vecLeft[indexLeft] <= vecRight[indexRight]){
			pVector[i] = vecLeft[indexLeft];
			indexLeft++;
		} else {
			pVector[i] = vecRight[indexRight];
			indexRight++;
		}
		i++;
	}
	while (indexLeft < (int)(vecLeft.size())){
		pVector[i] = vecLeft[indexLeft];
		indexLeft++;
		i++;
	}
	while (indexRight < (int)(vecRight.size())){
		pVector[i] = vecRight[indexRight];
		indexRight++;
		i++;
	}
}

void PmergeMe::insertionSort(std::vector<int> & pVector, int startIndex, int lastIndex){
	for (int i = startIndex + 1; i < lastIndex + 1; i++) {
		int temp = pVector[i];
		int j = i - 1;
		while (j >= startIndex && pVector[j] > temp) {
			pVector[j + 1] = pVector[j];
			j--;
		}
		pVector[j + 1] = temp;
	}
	if (PmergeMe::isVerbose()){
		std::cout << "INSERT: ";
		for (int i = startIndex; i < lastIndex + 1; i++)
			std::cout << pVector[i] << " ";
		std::cout << std::endl;
	}
}

void PmergeMe::sort(std::vector<int> & pVector, int startIndex, int lastIndex, int8_t isLeft){
	if (PmergeMe::isVerbose()){
		std::cout << "pVector: ";
		for (size_t i = 0; i < pVector.size(); i++)
			std::cout << i << " ";
		std::cout << std::endl;
		if (isLeft == -1)
			std::cout << "sorting left side..." << std::endl;
		else if (isLeft == 1)
			std::cout << "sorting right side..." << std::endl;
		else{
			std::cout << "sorting 1st call..." << std::endl;
		}
	}

	int middleIndex = startIndex + ((lastIndex - startIndex) / 2);
	if (lastIndex - startIndex > PmergeMe::getSizeThreshold()) {
		if (PmergeMe::isVerbose())
			std::cout << "startIndex: [" << startIndex << "]  lastIndex:[" << lastIndex << "]  middleIndex:["  << middleIndex << "]" << std::endl;
		// divides current vector slice left group
		PmergeMe::sort(pVector, startIndex, middleIndex, -1);
		// divides current vector slice  right group
		PmergeMe::sort(pVector, middleIndex + 1, lastIndex, 1);
		// merge sorts both groups after recursion
		PmergeMe::merge(pVector, startIndex, middleIndex, lastIndex);
	} else {
		// if elements are less than 6, does the insertion sort
		PmergeMe::insertionSort(pVector, startIndex, lastIndex);
	}
	return ;
}

void PmergeMe::sortVector(std::vector<int> & pVector){
	PmergeMe::sort(pVector, 0, pVector.size() - 1, 0);
}

// LIST --------------------------------

bool PmergeMe::isSorted(std::list<int> pList){
	std::list<int>::iterator it = pList.begin();
	std::list<int>::iterator jt = it;
	jt++;
	while (jt != pList.end()){
		if (*it > *jt)
			return false;
		it++;
		jt++;
	}
	return true;
}

std::list<int>::iterator PmergeMe::getNthIterator(std::list<int> & pList, int index){
	std::list<int>::iterator it = pList.begin();
	std::advance(it, index);
	return it;
}

void PmergeMe::insertionSort(std::list<int> & pList, int startIndex, int lastIndex){
	for (int i = startIndex + 1; i < lastIndex + 1; i++) {
		int temp = *getNthIterator(pList, i);
		int j = i - 1;
		while (j >= startIndex && *getNthIterator(pList, j) > temp) {
			*getNthIterator(pList,j + 1) = *getNthIterator(pList, j);
			j--;
		}
		*getNthIterator(pList, j + 1) = temp;
	}
	if (PmergeMe::isVerbose()){
		std::cout << "INSERT: ";
		for (int i = startIndex; i < lastIndex + 1; i++)
			std::cout << *getNthIterator(pList, i) << " ";
		std::cout << std::endl;
	}
}

void PmergeMe::merge(std::list<int> & pList, int startIndex, int middleIndex, int lastIndex){
	// builds the left and right side of the List
	int leftLimit = middleIndex - startIndex + 1;
	int rightLimit = lastIndex - middleIndex; 
	std::list<int> lstLeft;
	std::list<int> lstRight;

	for (int i = 0; i < leftLimit; i++)
	{
		lstLeft.push_back(*getNthIterator(pList, startIndex + i));
	}
	for (int i = 0; i < rightLimit; i++)
	{
		lstRight.push_back(*getNthIterator(pList , middleIndex + 1 + i));
	}

	if (PmergeMe::isVerbose()){
		std::cout << "List left ------------" << std::endl;
		std::cout << "lstLeft.size(): " << lstLeft.size() << std::endl;
		PmergeMe::printList(lstLeft);
		std::cout << "-------------------------" << std::endl;
		std::cout << "List right ------------" << std::endl;
		std::cout << "lstRight.size(): " << lstRight.size() << std::endl;
		PmergeMe::printList(lstRight);
		std::cout << "-------------------------" << std::endl;
		std::cout << "Merging startIndex:[" << startIndex << "] lastIndex:[" << lastIndex << "] midIndex:[" << middleIndex << "] delta:[" << lastIndex - startIndex << "]" << std::endl;
	}
	int indexLeft = 0;
	int indexRight = 0;
	int i = startIndex;
	while (indexLeft < (int)(lstLeft.size()) && indexRight < (int)(lstRight.size())){
		if (*getNthIterator(lstLeft, indexLeft) <= *getNthIterator(lstRight, indexRight)){
			*getNthIterator(pList, i) = *getNthIterator(lstLeft, indexLeft);
			indexLeft++;
		} else {
			*getNthIterator(pList, i) = *getNthIterator(lstRight, indexRight);
			indexRight++;
		}
		i++;
	}
	while (indexLeft < (int)(lstLeft.size())){
		*getNthIterator(pList, i) = *getNthIterator(lstLeft, indexLeft);
		indexLeft++;
		i++;
	}
	while (indexRight < (int)(lstRight.size())){
		*getNthIterator(pList, i) = *getNthIterator(lstRight, indexRight);
		indexRight++;
		i++;
	}
}

void PmergeMe::sort(std::list<int> & pList, int startIndex, int lastIndex, int8_t isLeft){
	if (PmergeMe::isVerbose())
		std::cout << "sorting list..." << std::endl;
	int middleIndex = startIndex + ((lastIndex - startIndex) / 2);
	if (lastIndex - startIndex > PmergeMe::getSizeThreshold()) {
		if (PmergeMe::isVerbose())
			std::cout << "startIndex: [" << startIndex << "]  lastIndex:[" << lastIndex << "]  middleIndex:["  << middleIndex << "]" << std::endl;
		// divides current vector slice left group
		PmergeMe::sort(pList, startIndex, middleIndex, -1);
		// divides current vector slice  right group
		PmergeMe::sort(pList, middleIndex + 1, lastIndex, 1);
		// merge sorts both groups after recursion
		PmergeMe::merge(pList, startIndex, middleIndex, lastIndex);
	} else {
		// if elements are less than 6, does the insertion sort
		PmergeMe::insertionSort(pList, startIndex, lastIndex);
	}
	(void)(isLeft);
	return ;
}

void PmergeMe::sortList(std::list<int> & pList){
	PmergeMe::sort(pList, 0, pList.size() - 1, 0);;
}

void PmergeMe::printList(std::list<int> list){
		int i = 0;
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		{
			std::cout << *it << " ";
			i++;
		}
		std::cout <<  std::endl;
		std::cout << "list entries: " << i << std::endl;
}

void PmergeMe::argvToList(std::list<int> & pList, int argc, char *argv[]){
	for (int i = 1; i < argc; i++)
		pList.push_back(std::atoi(argv[i]));
}