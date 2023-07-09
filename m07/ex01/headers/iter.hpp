/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:07:54 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/09 18:46:09 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> //size_t
#include <iostream>

template <typename T>
// Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be call on every element of the array.
void iter(T *array, size_t len, void (*fun)(T &arrayMember))
{
	for (size_t i = 0; i < len; i++)
		fun(array[i]);
	return ;
}

template <typename T>
// overload to be used with const values
void iter(T const *array, size_t len, void (*fun)(T const &arrayMember))
{
	for (size_t i = 0; i < len; i++)
		fun(array[i]);
	return ;
}

template <typename T>
void print_member(T const &arrayMember)
{
	std::cout << arrayMember << std::endl;
}

template <typename T>
void increment(T &arrayMember)
{
	arrayMember = arrayMember + 1;
}

template <typename T>
void square(T &arrayMember)
{
	arrayMember = arrayMember * arrayMember;
}
#endif // ITER_TPP
