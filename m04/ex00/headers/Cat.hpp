/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:12:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/08 20:58:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
	//------------ OCF
		Cat(void); // Default constructor
		Cat(const Cat & instance); // copy constructor
		Cat & operator=(const Cat & instance); // copy operator constructor
		~Cat(void);
	//------------
		Cat(std::string type);

		void makeSound(void) const;
	protected:

	private:
};

#endif // CAT_HPP
