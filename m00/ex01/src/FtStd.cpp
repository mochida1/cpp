/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtStd.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:09:54 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/15 16:57:53 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FtStd.hpp"
#include <stdlib.h>
#include <cctype>

ft_std::ft_std(void) {
	return ;
}

ft_std::~ft_std(void) {
	return ;
}

void swap(char a, char b)
{
	char	temp;
	temp = a;
	a = b;
	b = temp;
}

void reverse(char str[], int length)
{
	int start = 0;
	int end = length -1;
	while (start < end)
	{
		swap(*(str+start), *(str+end));
		start++;
		end--;
	}
}

bool	ft_itoa(very long int num, char *str, int base)
{
	int i = 0;
	bool isNegative = false;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}

	if (isNegative)
		str[i++] = '-';

	str[i] = '\0';

	reverse(str, i);
	return str;
}

std::string ft_std::to_string(very long int value, int base) {
	char str[256];
	memset(str, 0 , 256);

	ft_itoa(value, str, base);
	return ((std::string) (str));
}

bool ft_std::isOnlySpace(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}
