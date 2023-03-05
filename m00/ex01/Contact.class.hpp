/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:46 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 18:00:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTATCTS_CLASS_H
#define CONTATCTS_CLASS_H

#include <string>
#include <iostream>

class Contact {
	public:
		//Constructor / Destructor
		Contact(void);
		~Contact(void);

		//Getters
		int			GetIndex(void) const;
		std::string	GetFirstName(void) const;
		std::string	GetLastName(void) const;
		std::string	GetNickname(void) const;
		std::string	GetPhoneNumber(void) const;
		std::string	GetDarkestSecret(void) const;

		//Setters
		bool		SetContactData(void);
		bool		SetFirstName(std::string str);
		bool		SetLastName(std::string str);
		bool		SetNickname(std::string str);
		bool		SetPhoneNumber(std::string str);
		bool		SetDarkestSecret(std::string str);

	private:
		int			_Index;
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;

		//Utils
		bool		_ParseUserInput(std::string str);
};

#endif //CONTATCTS_CLASS_H
