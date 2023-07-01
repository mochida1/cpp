/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:27:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/30 21:14:36 by hmochida         ###   ########.fr       */
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
	~Base(void);
	std::string getClassName(void) const;
protected:
private:
	std::string _className;
};

#endif //BASE_HPP
