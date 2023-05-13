/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:40 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/12 21:28:16 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Form
{
	public:
	// OCF ----------------
		Form(void);
		Form(const Form & instance);
		Form & operator=(const Form & instance);
		~Form();
	// --------------------
	protected:
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
};

std::ostream &operator<<(std::ostream &outStream, Form const &instance);
