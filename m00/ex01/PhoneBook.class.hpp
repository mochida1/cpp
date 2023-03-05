/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:54 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 15:03:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	Add();
		bool	Search();
		bool	Exit();

	private:
		int		_ContactsFilled;
		Contact	_ContactArray[8];
};

#endif // PHONEBOOK_CLASS_H
