/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:42:51 by mochida           #+#    #+#             */
/*   Updated: 2023/07/29 18:13:39 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <algorithm>

class noOccurrencesException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "no occurrences found in container";
        }
};

template <typename T>
typename T::iterator easyfind(T &containerToSearchIn, int variableToSearchFor){
    typename T::iterator occurence;

    occurence = find(containerToSearchIn.begin(), containerToSearchIn.end(), variableToSearchFor);
    if ( occurence == containerToSearchIn.end() )
        throw noOccurrencesException();
    return occurence;
}

#endif // EASYFIND_TPP