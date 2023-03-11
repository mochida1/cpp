/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:54 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 21:07:29 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include <string>
#include "Contact.class.hpp"
#include "FtStd.class.hpp"

#define ACTION_ADD		1
#define ACTION_SEARCH	2
#define ACTION_EXIT		4

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	Add();
		bool	Search();
		bool	Exit();
		int		PromptUser();
		bool	DoAction (int control);

		//Debug
		bool	AutoAddSmall(int number_of_contacts);
		void	PrintContactData(int index);

	private:
		int		_ContactsFilled;
		Contact	_ContactArray[8];
};

#endif // PHONEBOOK_CLASS_H
