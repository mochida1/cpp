/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:13:36 by mochida           #+#    #+#             */
/*   Updated: 2023/10/09 21:44:16 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"
#include <list>
#include <cassert>

void TEST_subject_01()
{
	std::cout << "<<<<<<<<< starting " <<__FUNCTION__ << "(" << __FILE__ << ":" << __LINE__ << ")" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "ending " <<__FUNCTION__ << " >>>>>>>>>" << std::endl;
	return ;
}

void TEST_subject_02()
{
	std::cout << "<<<<<<<<< starting " <<__FUNCTION__ << "(" << __FILE__ << ":" << __LINE__ << ")" << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.front() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack); we can't use this because there are no constructos in std::stack that use a list object as a parameter. Yes, the subject keeps on fucking up.
	std::cout << "ending " <<__FUNCTION__ << " >>>>>>>>>" << std::endl;
	return ;
}

void TEST_iterator_validator()
{
	std::cout << "<<<<<<<<< starting " <<__FUNCTION__ << "(" << __FILE__ << ":" << __LINE__ << ")" << std::endl;
	MutantStack<int> mstack;
	for (int i = 0; i < 66000; i++) // populating all the shit;
	{
		mstack.push(i);
	}
	MutantStack<int>::iterator it = mstack.begin();
	for (int i = 0; i < 66000; i++) // here we check wether everything enter in the right order
	{
		if (i % 1000 == 0)
			std::cout << "i[" << i << "]    it[" << *it << "]" << std::endl;
		assert (i == *it);
		it++;
	}
	std::cout << "ending " <<__FUNCTION__ << " >>>>>>>>>" << std::endl;
	return ;
}

int main (void)
{
	TEST_subject_01();
	TEST_subject_02();
	TEST_iterator_validator();
	// not implementing tests to check iterators' inherited methods because too lazy to test something that already works.
	// GL trying to test it if you want.
	return 0;
}