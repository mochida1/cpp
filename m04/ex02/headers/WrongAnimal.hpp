/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:10 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/03 19:46:46 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
	//------------ OCF
		WrongAnimal(void); // Default constructor
		WrongAnimal(const WrongAnimal & instance); // copy constructor
		virtual WrongAnimal & operator=(const WrongAnimal & instance); // copy operator constructor
		virtual ~WrongAnimal(void);
	//------------
		WrongAnimal(std::string type);

		std::string getType(void) const;
		void makeSound(void) const;

	protected:
		std::string type;

	private:
};

#endif // WRONGANIMAL_HPP
