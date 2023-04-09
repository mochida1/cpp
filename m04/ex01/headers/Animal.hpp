/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:37 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/09 17:40:02 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
	//------------ OCF
		Animal(void); // Default constructor
		Animal(const Animal & instance); // copy constructor
		virtual Animal & operator=(const Animal & instance); // copy operator constructor
		virtual ~Animal(void);
	//------------
		Animal(std::string type);

		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string type;

	private:

};

#endif // ANIMAL_HPP
