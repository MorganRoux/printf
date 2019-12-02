/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:58:16 by mroux             #+#    #+#             */
/*   Updated: 2019/12/02 17:19:59 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	int		ret;
	char	flag;
	va_list	ap;

	va_start(ap, s);
	ret = 0;
	flag = 0;
	if (s == 0)
		return (-1);
	while (*s != 0)
	{
		if (flag != 0 )
			handle_args(&flag, &ap, *s);
		else if ((flag = is_flag(*s)) == 0)
			ft_putchar_fd(*s, 1);
		s++;
	}

	return ++ret;
}
