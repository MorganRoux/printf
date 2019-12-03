/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:10:46 by mroux             #+#    #+#             */
/*   Updated: 2019/12/02 19:46:29 by mroux            ###   ########.fr       */
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

void	print_arg(char *s, t_flags *flags)
{
	char	c;

	if (flags->pad == LEFT_ADJUSTED)
		print_arg_left(s, flags->len);
	else
	{
		c = (flags->pad == ZERO_PADDING) ? '0' : ' ';
		print_arg_right(s, flags->len, c);
	}

}

void	option_di(va_list *ap, t_flags *flags)
{
	int		len;
	char	*s;
	char	*zero;
	char	*nbr;

	nbr = ft_itoa(va_arg(*ap, int));
	len = flags->precision - ft_strlen(nbr);
	len = len < 0 ? 0 : len;
	zero = ft_calloc(len + 1, sizeof(char));
	ft_memset(zero, '0', len);
	zero[len] = 0;
	s = ft_strjoin(zero, nbr);
	print_arg(s, flags);
	free(nbr);
	free(s);
	free(zero);
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
	while (**s == '-' || **s == '0')
	{
		if (**s == '-')
			flags->pad = LEFT_ADJUSTED;
		else if (**s == '0' && flags->pad != LEFT_ADJUSTED)
			flags->pad = ZERO_PADDING;
		(*s)++;
	}
}

void	handle_digits(va_list *ap, const char **s, t_flags *flags)
{
	if (ft_isdigit(**s))
	{
		flags->len = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	else if (**s == '*')
	{
		flags->len = va_arg(*ap, int);
		(*s)++;
	}
}

void	handle_precision(va_list *ap, const char **s, t_flags *flags)
{
	flags->precision = 0;
	if (**s == '.')
	{
		(*s)++;
		if (ft_isdigit(**s))
		{
			flags->precision = ft_atoi(*s);
			while (ft_isdigit(**s))
				(*s)++;
		}
		else if (**s == '*')
		{
			flags->precision = va_arg(*ap, int);
			(*s)++;
		}
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
			handle_digits(ap, s, &flags);
			handle_precision(ap, s, &flags);
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
