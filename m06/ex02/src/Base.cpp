/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:52 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/30 21:15:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(void) : _className("Base") {
	return ;
}

Base::Base(std::string name) : _className(name) {
	return ;
}

Base::~Base(void) {
	return ;
}

std::string Base::getClassName(void) const {
	return this->_className;
}
