/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:34 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 20:55:38 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
	//------------ OCF
		Dog(void); // Default constructor
		Dog(const Dog & instance); // copy constructor
		Dog & operator=(const Dog & instance); // copy operator constructor
		~Dog(void);
	//------------
		Dog(std::string type);

		void makeSound(void) const;
	protected:

	private:
};

#endif // DOG_HPP
