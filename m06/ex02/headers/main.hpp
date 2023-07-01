/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:21:19 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/30 21:56:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MAIN_HPP
#define MAIN_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cassert>
#include <cstdlib>
#include <unistd.h>
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif // MAIN_HPP
