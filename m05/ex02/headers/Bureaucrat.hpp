/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:57:03 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/14 19:29:50 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#ifndef VERBOSE
# define VERBOSE 0
#endif //VERBOSE

# include <iostream>
# include "AForm.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat & instance);
		Bureaucrat & operator=(const Bureaucrat & instance);
		~Bureaucrat(void);
		Bureaucrat (std::string name, int grade);
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);
		void				increaseGrade(int grade);
		void				decreaseGrade(int grade);
		void				increaseGrade(void);
		void				decreaseGrade(void);
		bool				signForm(Form & instance);

		class GradeTooHighException
		{
			public:
				GradeTooHighException(void);
				~GradeTooHighException(void);
				/*
					since we're not overriding and reimplmenting
					the what() method of the exception class,
					it'll cause the program to exit with a SIGABORT!
				*/
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
		void				_validateGrade(int grade);
		const std::string	_name;
		int					_grade;

};
std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &instance);

#endif // BUREAUCRAT_HPP
