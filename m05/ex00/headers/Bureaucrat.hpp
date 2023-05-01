/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:57:03 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/30 20:15:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat & instance);
		Bureaucrat & operator=(const Bureaucrat & instance);
		~Bureaucrat(void);
		Bureaucrat (std::string name);
	protected:
	private:
		const std::string	_name;
		unsigned char		_grade;

};
std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &instance);

#endif // BUREAUCRAT_HPP
