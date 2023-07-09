/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wathever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:48:08 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/09 16:18:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

// • swap: Swaps the values of two given arguments. Does not return anything.
template <typename T>
void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
	return ;
}

// • min: Compares the two values passed in its arguments and returns the smallest
// one. If the two of them are equal, then it returns the second one.
template <typename T>
T &min(T &a, T &b) {
	if (a < b)
		return a;
	return b;
}

// • max: Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
T& max(T &a, T &b) {
	if (a > b)
		return a;
	return b;
}

#endif // WHATEVER_HPP
