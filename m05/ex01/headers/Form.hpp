/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:40 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/13 20:20:11 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#ifndef VERBOSE
# define VERBOSE 0
#endif //VERBOSE

class Form
{
	public:
	// OCF ----------------
		Form(void);
		Form(const Form & instance);
		Form & operator=(const Form & instance);
		~Form();
	// --------------------
		Form(std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute);

	// GETTERS
		const std::string	getName() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExecute() const;
		bool				getIsSigned() const;
	// SETTERS
		bool				setIsSigned(bool state);
		bool				setIsSigned(void);
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
