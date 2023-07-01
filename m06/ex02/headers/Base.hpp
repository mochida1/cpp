/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:27:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/01 16:40:27 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
# define BASE_HPP

#include <string>

class	Base{
public:
	Base(void);
	Base(std::string Base);
	virtual ~Base(void);
	std::string getClassName(void) const;
protected:
private:
	std::string _className;
};

#endif //BASE_HPP
