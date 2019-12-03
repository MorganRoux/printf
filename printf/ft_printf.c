/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:58:16 by mroux             #+#    #+#             */
/*   Updated: 2019/12/03 10:44:18 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	int		ret;
	va_list	ap;
	
	va_start(ap, s);
	ret = 0;
	if (s == 0)
		return (-1);
	while (*s != 0)
	{
		if (handle_args(&ap, &s) == 0)
			ft_putchar_fd(*s++, 1);
	}

	return ++ret;
}
