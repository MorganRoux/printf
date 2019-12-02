/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:10:46 by mroux             #+#    #+#             */
/*   Updated: 2019/12/02 19:45:42 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg_left(char *s, int len)
{
	int i;

	i = 0;
	while (s[i] != 0)
		ft_putchar_fd(s[i++], 1);
	while (i++ < len)
		ft_putchar_fd(' ', 1);
}

void	print_arg_right(char *s, int len, char c)
{
	int	i;
	int l;

	l = len - ft_strlen(s);
	i = 0;
	while (i++ < l)
		ft_putchar_fd(c, 1);
	ft_putstr_fd(s, 1);
}

void	option_di(va_list *ap, t_flags *flags)
{
	int		i;
	
	i = va_arg(*ap, int);
	if (flags->pad == 0)
		print_arg_left(ft_itoa(i), flags->len);
	else 
		print_arg_right(ft_itoa(i), flags->len, ' ' );
}
/*
void	option_c(va_list *ap, t_flags *flags)
{
	unsigned char	i;
	
	i = va_arg(*ap, int);
	ft_putchar_fd(i, 1);
}

void	option_s(va_list *ap, t_flags *flags)
{
	char	*s;
	
	s = va_arg(*ap, char *);
	ft_putstr_fd(s, 1);
}

*/
void	handle_flags(const char **s, t_flags *flags)
{
	while (**s == '-' || **s == '0' || **s == '.' || **s == '*' || ft_isdigit(**s))
	{
		if (ft_isdigit(**s))
		{
			flags->len = ft_atoi(*s);
			while (ft_isdigit(**s))
				(*s)++;
		}
		if(
	}
}

int		handle_args(va_list *ap, const char **s)
{
	(void)ap;
	t_flags	flags;
	flags.pad = 0;
	flags.len = 6;
	if (**s == '%')
	{
		(*s)++;
		if (**s == '%')
			ft_putchar_fd(*(*s)++, 1);
		else 
		{
			handle_flags(s, &flags);
			if (**s == 'd' || **s == 'i')
				option_di(ap, &flags);	
		/*	else if (c == 'c')
				option_c(ap, flags);	
			else if (c == 's')
				option_s(ap, flags);*/
			(*s)++;
		}
		return (1);
	}
	return (0);
}
