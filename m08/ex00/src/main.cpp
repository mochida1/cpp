/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:42:59 by mochida           #+#    #+#             */
/*   Updated: 2023/08/02 21:35:57 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"
#include <ctime>
#include <cassert>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>

int rc;

int rngeezus(int min, int max)
{
	int delta;
	int ret;

	if (min >= max)
		return 0;

	delta = max - min;
	ret = std::rand()%delta;
	ret += min;
	return ret;
}

int TEST_rands(void)
{
	srand(time(0));
	std::cout << "\n<<<<<<<<< TESTING RANDOM NUMBER GENERATOR <<<<<<<<<" << std::endl;
	std::cout << "Testing random ints deltas!" << std::endl;
	for (int i = 0; i < 100000; i++)
	{
		int randInt = rngeezus(1, 10);
		if (randInt < 1 || randInt > 10)
		{
			std::cerr << "FAILURE!!" << std::endl;
			return 1;
		}
	}
	std::cout << "Testing random ints collisions!" << std::endl;
	for (int i = 0; i < 100000; i++)
	{
		int randInt = rngeezus(1, 1500000);
		int compareInt = rngeezus(1, 1500000);
		if (randInt == compareInt)
		{
			if (i == 0)
			{
				std::cerr << "FAILURE! Two sequencial identical ints at the same time!" << std::endl;    
				return 2;
			}
			std::cerr << "WARNING! Two sequencial identical ints at the same time!" << std::endl;
			std::cerr << "at iteration [" << i << "]. Value of [" << randInt << "]" << std::endl;
		}
	}
	std::cout << ">>>>>>>>> Test of random numbers succeeded!" << std::endl;
	return 0;
}

int TEST_vector(void)
{
	std::cout << "\n<<<<<<<<< TESTING easyfind - VECTORS <<<<<<<<<" << std::endl;
	
	int toFind = 42;
	int vector_size = 42000;
	int instance_pos = vector_size;
	std::vector<int> haystack;
	std::vector<int>::iterator iter;
	haystack.resize(42000);
	assert (haystack.capacity() == (size_t)(vector_size));
	std::cout << "... populating vector with random values..." << std::endl;
	for (int i = 0; i < vector_size; i++)
	{
		int randomInt = rngeezus(1, 84000);
		if (randomInt == toFind)
		{
			std::cout << "instance generated at index [" << i << "]" << std::endl;
			if (instance_pos == vector_size)
			{
				instance_pos = i;
				std::cout << "keeping track of first occurence" << std::endl;
			}
		}
		haystack[i] = randomInt;
	}
	if (instance_pos == vector_size)
		std::cout << "no instance of number to find generated. Exception expeceted." << std::endl;
	try {
		iter = easyfind(haystack, toFind);
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: [" << e.what() << "]" << std::endl;
		std::cout << ">>>>>>>>> Test of easyfind - VECTORS succeeded!" << std::endl;
		return 0;
	}
	if (iter != haystack.end())
	{
		std::cout << "First instance found at index [" << std::distance(haystack.begin(), iter) << "]" <<std::endl;
		assert (std::distance(haystack.begin(), iter) == instance_pos);
	}
	else 
	{
		std::cerr << "Value to find was instantiated, but not found!" << std::endl;
		return 4;
	}
	std::cout << ">>>>>>>>> Test of easyfind - VECTORS succeeded!" << std::endl;
	return 0;
}

int TEST_deque()
{
	std::cout << "\n<<<<<<<<< TESTING easyfind - DEQUE <<<<<<<<<" << std::endl;
	
	int toFind = 42;
	int deque_size = 42000;
	int instance_pos = deque_size;
	std::deque<int> haystack;
	std::deque<int>::iterator iter;
	haystack.resize(42000);
	assert (haystack.size() == (size_t)(deque_size));
	std::cout << "... populating deque with random values..." << std::endl;
	for (int i = 0; i < deque_size; i++)
	{
		int randomInt = rngeezus(1, 84000);
		if (randomInt == toFind)
		{
			std::cout << "instance generated at index [" << i << "]" << std::endl;
			if (instance_pos == deque_size)
			{
				instance_pos = i;
				std::cout << "keeping track of first occurence" << std::endl;
			}
		}
		haystack[i] = randomInt;
	}
	if (instance_pos == deque_size)
		std::cout << "no instance of number to find generated. Exception expeceted." << std::endl;
	try {
		iter = easyfind(haystack, toFind);
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: [" << e.what() << "]" << std::endl;
		std::cout << ">>>>>>>>> Test of easyfind - DEQUES succeeded!" << std::endl;
		return 0;
	}
	if (iter != haystack.end())
	{
		std::cout << "First instance found at index [" << std::distance(haystack.begin(), iter) << "]" <<std::endl;
		assert (std::distance(haystack.begin(), iter) == instance_pos);
	}
	else 
	{
		std::cerr << "Value to find was instantiated, but not found!" << std::endl;
		return 8;
	}
	std::cout << ">>>>>>>>> Test of easyfind - DEQUES succeeded!" << std::endl;
	return 0;
}

int TEST_list(void)
{
	std::cout << "\n<<<<<<<<< TESTING easyfind - LIST <<<<<<<<<" << std::endl;
	
	int toFind = 42;
	int list_size = 42000;
	int instance_pos = list_size;
	std::list<int> haystack;
	std::list<int>::iterator iter;
	haystack.resize(42000);
	assert (haystack.size() == (size_t)(list_size));
	std::cout << "... populating list with random values..." << std::endl;
	iter = haystack.begin();
	for (int i = 0; i < list_size; i++)
	{
		int randomInt = rngeezus(1, 84000);
		if (randomInt == toFind)
		{
			std::cout << "instance generated at index [" << i << "]" << std::endl;
			if (instance_pos == list_size)
			{
				instance_pos = i;
				std::cout << "keeping track of first occurence" << std::endl;
			}
		}
		*iter = randomInt;
		std::advance(iter, 1);
	}
	if (instance_pos == list_size)
		std::cout << "no instance of number to find generated. Exception expeceted." << std::endl;
	try {
		iter = easyfind(haystack, toFind);
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: [" << e.what() << "]" << std::endl;
		std::cout << ">>>>>>>>> Test of easyfind - LISTS succeeded!" << std::endl;
		return 0;
	}
	if (iter != haystack.end())
	{
		std::cout << "First instance found at index [" << std::distance(haystack.begin(), iter) << "]" <<std::endl;
		assert (std::distance(haystack.begin(), iter) == instance_pos);
	}
	else 
	{
		std::cerr << "Value to find was instantiated, but not found!" << std::endl;
		return 8;
	}
	std::cout << ">>>>>>>>> Test of easyfind - LISTS succeeded!" << std::endl;
	return 0;
}

int TEST_set(void)
{
	std::cout << "\n<<<<<<<<< TESTING easyfind - SETs <<<<<<<<<" << std::endl;
	
	int toFind = rngeezus(1, 84000);
	int set_size = 42000;
	int instance_pos = set_size;
	std::set<int> haystack;
	std::set<int>::iterator iter;
	int randomInt;
	std::cout << "instance to find is: [" << toFind << "]" << std::endl;
	std::cout << "... populating set with values" << std::endl;
	iter = haystack.begin();
	std::pair<std::set<int>::iterator, bool> ret;
	ret.second = false;
	for (int i = 0; i < set_size; i++)
	{
		randomInt = rngeezus(1, 84000);
		ret = haystack.insert(randomInt);
		if (randomInt == toFind)
		{
			std::cout << "instance generated at iteration [" << i << "]" << std::endl;
			if (instance_pos == set_size)
			{
				instance_pos = i;
				std::cout << "index at generation is [" << std::distance(haystack.begin(), ret.first) << "]" << std::endl;
				std::cout << "keeping track of first occurence" << std::endl;
			}
		}
		while (ret.second == false)
		{
			iter = ret.first;
			randomInt = rngeezus(1, 84000);
			ret = haystack.insert(randomInt);
		}
	}
	// for (iter = haystack.begin(); iter != haystack.end(); ++iter)
	// 	std::cout << *iter << std::endl;
	std::cout << "set size: " << haystack.size() << std::endl;
	assert (haystack.size() == (unsigned long)(set_size));
	try {
		iter = easyfind(haystack, toFind);
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: [" << e.what() << "]" << std::endl;
		if (instance_pos >= set_size)
		{
			std::cout << ">>>>>>>>> Test of easyfind - SETs succeeded!" << std::endl;
			return 0;
		}
		std::cerr << "FAILURE AT SET TESTS!!!!" << std::endl;
		return 16;		
	}
	if (iter != haystack.end())
	{
		std::cout << "First instance found at index [" << std::distance(haystack.begin(), iter) << "]" << std::endl;
	}
	else 
	{
		std::cerr << "Value to find was instantiated, but not found!" << std::endl;
		return 32;
	}
	std::cout << ">>>>>>>>> Test of easyfind - SETs succeeded!" << std::endl;
	return 0;
}

int main(void)
{
	rc = 0;
	rc |= TEST_rands();
	rc |= TEST_vector();
	rc |= TEST_deque();
	rc |= TEST_list();
	rc |= TEST_set();

	if (rc)
		std::cerr << "TESTS FAILED as RC check: " << rc << std::endl;

	return rc;
}
