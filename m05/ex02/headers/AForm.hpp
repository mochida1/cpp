/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:40 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/19 23:15:44 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

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
		#ifdef EX01_TESTS
		virtual ~Form(void);
		# else // EX01_TESTS
		virtual ~Form(void) = 0;
		#endif //EX01_TESTS
	// --------------------
		Form(std::string target);
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(std::string target, std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute);

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
		virtual void				print(void) const;
		bool				execute(Bureaucrat const & executor) const;
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
		class ExecuteGradeTooLowException
		{
			public:
				ExecuteGradeTooLowException(void);
				~ExecuteGradeTooLowException(void);
				virtual const char* what() const throw();
		};
		class ExecuteFormUnsignedException
		{
			public:
				ExecuteFormUnsignedException(void);
				~ExecuteFormUnsignedException(void);
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
		int					_validateExecuteRequirements(Bureaucrat instance) const;
		void				_doFormAction(void) const;
};
std::ostream &operator<<(std::ostream &outStream, Form const &instance);


#endif // AFORM_HPP
