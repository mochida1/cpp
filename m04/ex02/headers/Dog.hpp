/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:34 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/09 18:08:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include "typeinfo"

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
		const Brain* getBrain(void) const;
		void setBrain(Brain * brain);
	protected:

	private:
		Brain *_dogBrain;
};

#endif // DOG_HPP
