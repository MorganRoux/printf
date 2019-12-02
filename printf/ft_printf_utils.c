/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:10:46 by mroux             #+#    #+#             */
/*   Updated: 2019/12/02 17:20:16 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_args(char *flag, va_list *ap, char c)
{
	(void)ap;
	if (*flag == '%')
	{
		if (c == '%')
			ft_putchar_fd(c, 1);
	}
	*flag = 0;
	return ;
}

char	is_flag(char c)
{
	if (c == '%')
		return ('%');
	return (0);
}
