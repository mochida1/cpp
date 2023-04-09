/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:03:37 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 21:12:19 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
	//------------ OCF
		WrongCat(void); // Default constructor
		WrongCat(const WrongCat & instance); // copy constructor
		WrongCat & operator=(const WrongCat & instance); // copy operator constructor
		~WrongCat(void);
	//------------
		WrongCat(std::string type);

		void makeSound(void) const;
	protected:

	private:
};

#endif // WRONGCAT_HPP
