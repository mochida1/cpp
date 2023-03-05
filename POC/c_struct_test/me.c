/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:31:10 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/04 21:34:53 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct    s_test
{
    int        intv;
    char    charv;
    void    *voidv;
    char    *strv;
}    t_test;

int main(void)
{
    t_test    test;

	printf ("test Address: %p\n", &test);
	test.intv = 51;
	test.charv = 'A';
	test.voidv = &test.charv;
	test.strv = "this is test\n";

    test = (t_test) {0};
	printf ("test Address: %p\n", &test);
    printf("intv: %i\n", test.intv);
    printf("charv: %i\n", test.charv);
    printf("voidv: %p\n", test.voidv);
    printf("strv: %s\n", test.strv);
}
