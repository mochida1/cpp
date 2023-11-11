/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:11:29 by mochida           #+#    #+#             */
/*   Updated: 2023/11/11 12:25:10 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// OCF ----------------------------

Span::Span(void) : _maxElements(0), _totalElements(0) , _isDataSorted(false) {
	this->_data.resize(0);
	return ;
}

Span::~Span(void) {
	return ;
}

Span & Span::operator=(Span &instance) {
	this->_data = instance.getData();
	this->_maxElements = instance.getMaxElements();
	this->_totalElements = instance.getTotalElements();
	this->_isDataSorted = instance.getIsDataSorted();
	return *this;
}

Span::Span(Span & instance) {
	*this = instance;
	return ;
}

//---------------------------- OCF

Span::Span(unsigned int N) : _maxElements(N), _totalElements(0), _isDataSorted(false){
	_data.reserve(N);
}

//////////////////////////////////////////////////////////////

int					Span::addNumber(int number) {
	if (this->_maxElements <= this->_totalElements)
	{
		throw maxElementsReached();
		return 1;
	}
	this->_data.push_back(number);
	this->_totalElements++;
	this->_isDataSorted = false;
	return 0;
}

int				Span::addNumber(std::vector<int>::iterator rangeBegin, std::vector<int>::iterator rangeEnd){
	std::vector<int>::iterator itBegin = rangeBegin;
	std::vector<int>::iterator itEnd = rangeEnd;
	if (rangeBegin > rangeEnd){
		itBegin = rangeEnd;
		itEnd = rangeBegin;
	}
	if (itEnd > this->_data.end())
		itEnd = this->_data.end();
	while (itBegin != itEnd)
	{
		addNumber(*itBegin);
		itBegin++;
	}
	addNumber(*itBegin);
	return 0;
}

int					Span::shortestSpan(void) {
	if (this->_maxElements <= 1 || this->_totalElements <= 1)
	{
		throw invalidNumberOfElements();
		return -1;
	}
	this->_sortData();
	if (this->_isDataSorted == true)
	{
		return this->_findSmallestPair();
	}
	return -2;
}

int					Span::longestSpan(void) {
	if (this->_maxElements <= 1 || this->_totalElements <= 1)
	{
		throw invalidNumberOfElements();
		return -1;
	}
	this->_sortData();
	if (this->_isDataSorted == true)
	{
		return ( *this->_data.rbegin() - *this->_data.begin());
	}
	return -2;
}

std::vector<int>	Span::getData(void) const {
	return this->_data;
}

unsigned int		Span::getMaxElements(void) const {
	return this->_maxElements;
}

unsigned int		Span::getTotalElements(void) const {
	return this->_totalElements;
}

bool				Span::getIsDataSorted(void) const {
	return this->_isDataSorted;
}

void				Span::print(void) {
	std::vector<int>::iterator i;
	
	for (i = this->_data.begin(); i < this->_data.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

bool				Span::test_sortData(void) {
	return this->_sortData();
}

// PRIVATE

int					Span::_findSmallestPair(void) {
	std::vector<int>::iterator i;
	int last;
	int ret;

	ret = 2147483647;
	i = this->_data.begin();
	last = *i;
	i++;
	for (; i < this->_data.end(); i++)
	{
		if ((*i - last) < ret)
			ret = *i - last;
		last = *i;
	}
	return ret;
}

bool				Span::_sortData(void) {
	if (this->_maxElements <= 1)
		return false;
	if (this->_totalElements <= 1)
		return false;
	if (this->_isDataSorted == true)
		return true;
	std::sort(this->_data.begin(), this->_data.end());
	this->_isDataSorted = true;
	return true;
}