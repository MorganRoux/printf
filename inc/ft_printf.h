/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:58:33 by mroux             #+#    #+#             */
/*   Updated: 2019/12/02 19:45:45 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int		len;
	int		pad;
	char	c;
}				t_flags;

int				ft_printf(const char *s, ...);
int				handle_args(va_list *ap, const char **s);
char			is_flag(char c);

#endif
