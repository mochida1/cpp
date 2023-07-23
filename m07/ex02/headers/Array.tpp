/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:00:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/22 16:26:29 by hmochida         ###   ########.fr       */
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
	Array(void): _n(0), _ptr(NULL){
		return ;
	};

	Array(unsigned int n): _n(n), _ptr(new T[n]) {
		return ;
	};

	Array (Array &instance) : _n(instance.size()), _ptr(new T[this->_n]) {
		*this = instance;
		return ;
	};

	T &operator[](unsigned int index) {
		if (index >= this->_n)
			throw OutOfRangeExc();
		return this->_ptr[index];
	}

	Array &operator=(Array const &instance) {
		if (this->_ptr != NULL)
			delete [] this->_ptr;
		this->_n = instance.size();
		this->_ptr = new T[this->_n];
		try {
			for (unsigned int i = 0; i < instance._n; i++)
			{
				if (i >= instance._n || i >= this->_n)
					throw OutOfRangeExc();
				this->_ptr[i] = instance._ptr[i];
			}
		}

		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		return *this;
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

	unsigned int _n;
	T *_ptr;
};


#endif // ARRAY_HPP
