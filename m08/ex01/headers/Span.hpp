/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:09:16 by mochida           #+#    #+#             */
/*   Updated: 2023/08/05 22:52:20 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class maxElementsReached : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Max elements reached in Span Class";
		}
};

class invalidNumberOfElements : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Invalid Number of Elements";
		}
};

class Span {
public:
	// OCF -------------------
	Span(void);
	~Span();
	Span &operator=(Span &instance);
	Span(Span & instance);
	Span(unsigned int N);
	// ------------------- OCF
	int					addNumber(int number);
	int					shortestSpan(void);
	int					longestSpan(void);
	std::vector<int>	getData(void) const;
	unsigned int		getMaxElements(void) const;
	unsigned int		getTotalElements(void) const;
	bool				getIsDataSorted(void) const;
	void				print(void);
	bool				test_sortData(void);
	
private:
	bool				_sortData(void);
	int					_findSmallestPair(void);
	std::vector<int>	_data;
	unsigned int		_maxElements;
	unsigned int		_totalElements;
	bool				_isDataSorted;
};

#endif //SPAN_HPP