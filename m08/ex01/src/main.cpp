/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:42:45 by mochida           #+#    #+#             */
/*   Updated: 2023/11/11 12:27:04 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cassert>
#include <ctime>
#include <iomanip>

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

void TEST_constructors(void){
	Span spam;	
	Span spam1(25);
	spam = spam1;
}

void TEST_addNumber(void){
	std::cout << "\n############# addNumber() #############" << std::endl;
	Span spam_ok(20);

	std::vector<int>::iterator iter;
	for (int i=0; i<20; i++)
	{
		try{spam_ok.addNumber(rngeezus(-10000, 25000));}
		catch (const std::exception&e)
		{
			std::cout << "FAILURE!!!" << e.what() << std::endl;
		}
	}
	std::cout << "printing SPAM_OK numbers" << std::endl;
	spam_ok.print(); 
	std::cout << "max elements:	[" << spam_ok.getMaxElements()<< "]" << std::endl;
	std::cout << "total elements:	[" << spam_ok.getTotalElements() << "]" << std::endl;

	Span spam_ko(20);
	for (int i=0; i<50; i++)
	{
		try{spam_ko.addNumber(rngeezus(-10000, 25000));}
		catch (const std::exception&e)
		{
			std::cout << "Exception thrown successfully!!!" << e.what() << std::endl;
			std::cout << "\t[spam_ko] at iteration [" << i << "], maxElements: [" << spam_ko.getMaxElements() << "], totalElements: [" << spam_ko.getTotalElements() << "]" << std::endl;
			break ;
		}
	}
}

void TEST_addNumberOverload(void){
	std::cout << "\n############# addNumber() OVERLOAD #############" << std::endl;
	Span spam_ok(20);

	std::vector<int> vec;
	std::vector<int>::iterator iter;

	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rngeezus(-10000, 25000));
	}
	try{spam_ok.addNumber(vec.begin(), vec.end());}
	catch (const std::exception&e)
	{
		std::cout << "FAILURE!!!" << e.what() << std::endl;
	}
	std::cout << "printing SPAM_OK numbers" << std::endl;
	spam_ok.print(); 
	std::cout << "max elements:	[" << spam_ok.getMaxElements()<< "]" << std::endl;
	std::cout << "total elements:	[" << spam_ok.getTotalElements() << "]" << std::endl;

	Span spam_ko(20);
	std::vector<int> vec_ko;
	for (int i = 0; i < 50; i++)
	{
		vec_ko.push_back(rngeezus(-10000, 25000));
	}
	for (int i=0; i<50; i++)
	{
		try{spam_ko.addNumber(vec_ko.begin(), vec_ko.end());}
		catch (const std::exception&e)
		{
			std::cout << "Exception thrown successfully!!!" << e.what() << std::endl;
			std::cout << "\t[spam_ko] at iteration [" << i << "], maxElements: [" << spam_ko.getMaxElements() << "], totalElements: [" << spam_ko.getTotalElements() << "]" << std::endl;
			break ;
		}
	}
}

void TEST_sort(void){
	std::cout << "\n############# _sort() #############" << std::endl;
	Span spam_ok(20);

	for (int i=0; i<20; i++)
	{
		try{spam_ok.addNumber(rngeezus(-10000, 25000));}
		catch (const std::exception&e)
		{
			std::cout << "FAILURE!!!" << e.what() << std::endl;
		}
	}
	std::cout << "printing SPAM_OK numbers BEFORE  sort" << std::endl;
	std::cout << "[spam_ok] is data sorted: " << spam_ok.getIsDataSorted() << std::endl;
	spam_ok.print(); 
	spam_ok.test_sortData();
	std::cout << "printing SPAM_OK numbers AFTER sort" << std::endl;
	std::cout << "[spam_ok] is data sorted: " << spam_ok.getIsDataSorted() << std::endl;
	spam_ok.print(); 
}

void TEST_longestSpan(void){
	std::cout << "\n############# longestSpan() #############" << std::endl;
	Span spam_ok(20);


	for (int i=0; i<20; i++)
	{
		try{spam_ok.addNumber(rngeezus(-10000, 25000));}
		catch (const std::exception&e)
		{
			std::cout << "FAILURE!!!" << e.what() << std::endl;
		}
	}
	std::cout << "printing SPAM_OK numbers" << std::endl;
	spam_ok.print(); 
	std::cout << "max elements:	[" << spam_ok.getMaxElements()<< "]" << std::endl;
	std::cout << "total elements:	[" << spam_ok.getTotalElements() << "]" << std::endl;

	std::cout << "longest span: [" << spam_ok.longestSpan() << "]" << std::endl;
	spam_ok.print();

	Span justTwo(2);
	justTwo.addNumber(0);
	justTwo.addNumber(10);
	assert (justTwo.longestSpan() == 10);
	std::cout << "just Two longest span should be 10 : [" << justTwo.longestSpan() << "]" << std::endl;
	
	Span spam_100k(100000);
	for (int i=0; i<100000; i++)
	{
		try{spam_100k.addNumber(rngeezus(-100000, 100000));}
		catch (const std::exception&e)
		{
			std::cout << "FAILURE!!!" << e.what() << std::endl;
		}
	}
	std::cout << "spam_100k: [" << spam_100k.longestSpan() << "]" << std::endl;
	Span span_test_exc(10);
	try {
		std::cout << "Longest span no elements. Should throw exception. >>" << std::endl;
		span_test_exc.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception thrown successfully: " << e.what() << std::endl;
	}
	span_test_exc.addNumber(1);	
	try {
		std::cout << "Longest span one elements. Should throw exception." << std::endl;
		span_test_exc.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception thrown successfully: " << e.what() << std::endl;
	}
}

void TEST_shortestSpan(void)
{
	std::cout << "\n############# shortestSpan() #############" << std::endl;
	Span span_test(5);
	span_test.addNumber(1);
	span_test.addNumber(7);
	span_test.addNumber(10);
	span_test.addNumber(12);
	try {
		std::cout << "Shortest span: [" << span_test.shortestSpan() << "]" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "This shouldn't have happened..." << std::endl;
	}
	Span span_test_exc(10);
	try {
		std::cout << "Shortest span no elements. Should throw exception. >>" << std::endl;
		span_test_exc.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception thrown successfully: " << e.what() << std::endl;
	}
	span_test_exc.addNumber(1);	
	try {
		std::cout << "Shortest span one elements. Should throw exception." << std::endl;
		span_test_exc.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception thrown successfully: " << e.what() << std::endl;
	}
}

int main (void)
{
	std::cout << "RUNNING ex01 TESTS >>>>>>>>>>>>>>>>>>>" << std::endl;
	srand(time(0));
	TEST_constructors();
	TEST_addNumber();
	TEST_addNumberOverload();
	TEST_sort();
	TEST_longestSpan();
	TEST_shortestSpan();
	std::cout << "<<<<<<<<<<<<<<<<<<<< ENDING ex01 TESTS" << std::endl;
	return 0;
}