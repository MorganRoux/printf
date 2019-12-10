/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:10:46 by mroux             #+#    #+#             */
/*   Updated: 2019/12/03 15:47:50 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(char *s, t_flags *flags)
{
	char	c;
	int		i;
	int		l;
	
	if (flags->left_pad)
	{
		i = 0;
		while (s[i] != 0)
			ft_putchar_fd(s[i++], 1);
		while (i++ < flags->len)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		c = (flags->zero_pad  && flags->precision == -1) ? '0' : ' ';
		l = flags->len - ft_strlen(s);
		i = 0;
		while (i++ < l)
			ft_putchar_fd(c, 1);
		ft_putstr_fd(s, 1);
	}
}

void	print_arg_nbr(char *s, t_flags *flags)
{
	int		i;
	char	c;

	i = 0;
	if (flags->left_pad)
	{
		while (s[i] != 0)
			ft_putchar_fd(s[i++], 1);
		while (i++ < flags->len)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		if ((flags->zero_pad  && flags->precision == -1))
		{
			c = '0';
			if (s != 0 && s[0] == '-')
			{
				ft_putchar_fd('-', 1);
				s++;
				i++;
			}
		}
		else
			c = ' ';

		while (i++ < flags->len - (int) ft_strlen(s))
			ft_putchar_fd(c, 1);
		ft_putstr_fd(s, 1);
	}
}


void	print_arg_c(char c, t_flags *flags)
{
	char	fill;
	int		i;
	int		l;
	
	if (flags->left_pad)
	{
		i = 1;
		ft_putchar_fd(c, 1);
		while (i++ < flags->len)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		fill = (flags->zero_pad  && flags->precision == -1) ? '0' : ' ';
		l = flags->len - 1;
		i = 0;
		while (i++ < l)
			ft_putchar_fd(fill, 1);
		ft_putchar_fd(c, 1);
	}
}

int	option_diuxX(va_list *ap, t_flags *flags, char type)
{
	int		len;
	char	*s;
	char	*zero;
	char	*nbr;
	int	n;

	n = va_arg(*ap, int);
	if (type == 'd' || type == 'i')
		nbr = ft_itoa(n);
	else if (type == 'x' || type == 'X')
		nbr = ft_uitoa_base(n, type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	else if (type == 'u')
		nbr = ft_uitoa_base(n, "0123456789");
	else
		return (0);
	len = flags->precision - ft_strlen(nbr);
	len = len < 0 ? 0 : len;
	if (!(zero = ft_calloc(len + 1, sizeof(char))))
		return (-1);
	ft_memset(zero, '0', len);
	zero[len] = 0;
	s = (n < 0 && (type == 'd' || type == 'i')) ? ft_strjoin("-", ft_strjoin(zero, &nbr[1])) : ft_strjoin(zero, nbr);
	print_arg_nbr(s, flags);
	flags->nprint += (ft_strlen(s) > (unsigned long) flags->len) ? ft_strlen(s) : flags->len;
	free(nbr);
	free(s);
	free(zero);
	return (0);
}

void	option_c(va_list *ap, t_flags *flags)
{
	unsigned char	i;
	
	i = va_arg(*ap, int);
	print_arg_c(i, flags);
	flags->nprint += (1 > (unsigned long) flags->len) ? 1 : flags->len;
}

void	option_s(va_list *ap, t_flags *flags)
{
	char	*s;

	if ((s = va_arg(*ap, char *)) == 0)
		s = ft_strdup("(null)");
	s = ft_substr(s, 0, flags->precision);
	flags->nprint += (ft_strlen(s) > (unsigned long) flags->len) ? ft_strlen(s) : flags->len;
	print_arg(s, flags);
	free(s);
}

void	option_p(va_list *ap, t_flags *flags)
{	
	long		len;
	char	*s;
	char	*zero;
	char	*nbr;
	void	*p;

	long	l;
	l = (long) ap;
	

	p = va_arg(*ap, void *);
	nbr = ft_ultoa_base((unsigned long) p, "0123456789abcdef");
	len = flags->precision - ft_strlen(nbr);
	len = len < 0 ? 0 : len;
	if (!(zero = ft_calloc(len + 1, sizeof(char))))
		return ;
	ft_memset(zero, '0', len);
	zero[len] = 0;
	s = ft_strjoin(zero, nbr);
	ft_putstr_fd("0x", 1);
	print_arg(s, flags);
	flags->nprint += (ft_strlen(s) > (unsigned long) flags->len) ? ft_strlen(s) : flags->len;
	free(nbr);
	free(s);
	free(zero);

}

void	handle_flags(const char **s, t_flags *flags)
{
	while (**s == '-' || **s == '0')
	{
		if (**s == '-')
			flags->left_pad = !flags->left_pad;
		else if (**s == '0')
			flags->zero_pad = 1;
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
	if (flags->len < 0)
	{
		flags->len = -flags->len;
		flags->left_pad = !flags->left_pad;
	}
	
	
}

void	handle_precision(va_list *ap, const char **s, t_flags *flags)
{
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

int		handle_type(va_list *ap, const char **s, t_flags *flags)
{
	if (**s == 'd' || **s == 'i' || **s == 'u' || **s == 'x' || **s == 'X')
	{
		if (option_diuxX(ap, flags, **s) == -1)
			return (-1);
	}
	else if (**s == 'c')
		option_c(ap, flags);	
	else if (**s == 's')
		option_s(ap, flags);
	else if (**s == 'p')
		option_p(ap, flags);
	return (0);
}

int		handle_args(va_list *ap, const char **s, t_flags *flags)
{
	if (**s == '%')
	{
		(*s)++;
		if (**s == '%')
		{
			ft_putchar_fd(*(*s)++, 1);
			flags->nprint++;
		}
		else 
		{
			handle_flags(s, flags);
			handle_digits(ap, s, flags);
			handle_precision(ap, s, flags);
			if (handle_type(ap, s, flags) == -1)
				return (-1);
			(*s)++;
		}
		return (1);
	}
	return (0);
}
