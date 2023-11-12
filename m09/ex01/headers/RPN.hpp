/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:31:15 by mochida           #+#    #+#             */
/*   Updated: 2023/11/12 19:09:54 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <deque>
#include <sstream>

class RPN{
public:
	RPN(std::string input); 
	~RPN(void); // default destructor

	void printInput(void);
	static bool validateInput(std::string input);
	void run(void);
	void setVerbose(bool status);
protected:
private:
	RPN(void); //default constuctor
	RPN(RPN & instance); //copy
	RPN & operator=(RPN & instance); // copy op
	std::string _input;
	bool _verbose;
};

#endif //RPN_HPP