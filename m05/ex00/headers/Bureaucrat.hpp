/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:57:03 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/07 19:27:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat & instance);
		Bureaucrat & operator=(const Bureaucrat & instance);
		~Bureaucrat(void);
		Bureaucrat (std::string name, int grade);
		const std::string getName(void) const;
		int getGrade(void) const;
		class GradeTooHighException
		{
			public:
				GradeTooHighException(void);
				~GradeTooHighException(void);
				virtual const char* what() const throw();
		};
		class GradeTooLowException
		{
			public:
				GradeTooLowException(void);
				~GradeTooLowException(void);
				virtual const char* what() const throw();
		};

	protected:
	private:
		bool				_testGrade(int grade) const;
		const std::string	_name;
		int		_grade;

};
std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &instance);

#endif // BUREAUCRAT_HPP
