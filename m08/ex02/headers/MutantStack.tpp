/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:14:08 by mochida           #+#    #+#             */
/*   Updated: 2023/10/09 20:49:09 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include <iostream>
#include <stack>

template <class T, class Container = std::deque<T> > // https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators why we use deque instead of stack
class MutantStack : public std::stack<T, Container>
{
	public:
	MutantStack(void) {return;};
	~MutantStack(void) {return;};
	MutantStack &operator=(MutantStack const &instance) {
		std::stack<T, Container>::operator=(instance);
		return *this;
	};
	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	iterator begin() {
		return this->c.begin();
	};
	iterator end() {
		return this->c.end();
	};
	reverse_iterator rbegin(void) {
		return this->c.rbegin();
	};
	reverse_iterator rend(void) {
		return this->c.rend();
	};
	private:
};

#endif // MUTANTSTACK_TPP