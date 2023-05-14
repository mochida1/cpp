/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:40 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/14 20:00:47 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#endif //VERBOSE

class Bureaucrat;

class Form
{
	public:
	// OCF ----------------
		Form(void);
		Form(const Form & instance);
		virtual Form & operator=(const Form & instance);
		virtual ~Form(void);
	// --------------------
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute);

	// GETTERS
		const std::string	getName(void) const;
		int					getGradeRequiredToSign(void) const;
		int					getGradeRequiredToExecute(void) const;
		bool				getIsSigned(void) const;
		const std::string	getTarget(void) const;
	// SETTERS
		bool				setIsSigned(bool state);
		bool				setIsSigned(void);
		bool				setTarget(std::string target);
	// CUSTOM
		bool				beSigned(Bureaucrat instance);
	// EXCEPTIONS
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
		std::string			target_;
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
		bool				_testGrade(int grade) const;
		bool				_validateGrade(int grade);
		int					_validateSignRequirements(Bureaucrat instance) const;
};

std::ostream &operator<<(std::ostream &outStream, Form const &instance);

#endif // FORM_HPP
