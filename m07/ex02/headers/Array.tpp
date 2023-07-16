/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:00:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/16 20:00:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class Array{
public:
	Array(void): _n(0), _ptr(NULL){return ;};
	Array(unsigned int n): _ptr(new T[n]), _n(n){return ;};
	T &operator[](unsigned int index) {
		if (index < 0 || index >= this->_n)
			throw OutOfRangeExc();
		return this->_ptr[index];
	}
	Array &operator=(Array const &instance) const{
		// this->_ptr
		(void)(instance);
	}
	~Array(void){
		if (this->_ptr)
			delete[] this->_ptr;
	}
	unsigned int size(void) const {
		return this->_n;
	};
protected:
private:
	class OutOfRangeExc : public std::exception {
		public:
		virtual const char *what(void) const throw(){
			return "Y U NO RESPECT LIMITS?!";
		}
	};
	T *_ptr;
	const unsigned int _n;
};


#endif // ARRAY_HPP
