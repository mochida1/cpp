/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:38:08 by mochida           #+#    #+#             */
/*   Updated: 2023/11/20 22:45:32 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <iterator>


// this is not instantiable. Screw OCF
class PmergeMe
{
public:
	~PmergeMe();
	//vector
	static bool isSorted(std::vector<int> pVector);
	static std::vector<int>::iterator getNthIterator(std::vector<int> & pVector, int index);
	static void insertionSort(std::vector<int> & pVector, int startIndex, int lastIndex);
	static void merge(std::vector<int> & vector, int startIndex, int middleIndex, int lastIndex);
	static void sort(std::vector<int> & vector, int startIndex, int lastIndex, int8_t isLeft);
	static void sortVector(std::vector<int> & pVector);
	static void printVector(std::vector<int> vector);
	static void argvToVector(std::vector<int> & vector, int argc, char *argv[]);
	// list
	static bool isSorted(std::list<int> pList);
	static std::list<int>::iterator getNthIterator(std::list<int> & pList, int index);
	static void insertionSort(std::list<int> & pList, int startIndex, int lastIndex);
	static void merge(std::list<int> & pList, int startIndex, int middleIndex, int lastIndex);
	static void sort(std::list<int> & pList, int startIndex, int lastIndex, int8_t isLeft);
	static void sortList(std::list<int> & pList);
	static void printList(std::list<int> list);
	static void argvToList(std::list<int> & pList, int argc, char *argv[]);
	// utils
	static bool isVerbose(void);
	static int getSizeThreshold(void);

private:
	static const bool _verbose = false;
	PmergeMe(PmergeMe & instance);
	PmergeMe(void);
	static const int _sizeThreshold = 5;
};




#endif // PMERGEME_HPP