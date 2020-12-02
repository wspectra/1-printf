/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:38 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/28 21:33:39 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr(t_strt *strt, int len, char *str)
{
	int i;

	i = 0;
	while (len > 0)
	{
		write(1, &str[i], 1);
		len--;
		i++;
		strt->count++;
	}
}

static void	ft_put_zero(t_strt *strt, int len)
{
	int n;

	n = strt->width - len;
	while (n > 0)
	{
		write(1, "0", 1);
		strt->count++;
		n--;
	}
}

static void	ft_put_space(t_strt *strt, int len)
{
	int n;

	n = strt->width - len;
	while (n > 0)
	{
		write(1, " ", 1);
		strt->count++;
		n--;
	}
}

void		ft_if_string(t_strt *strt)
{
	char	*str;
	int		len;

	str = (char*)va_arg(strt->ap, char*);
	len = ft_strlen(str);
	if (len > strt->precision && strt->precision != -1)
		len = strt->precision;
	if (strt->minus && strt->width > 0)
	{
		ft_putstr(strt, len, str);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->width > 0)
	{
		ft_put_zero(strt, len);
		ft_putstr(strt, len, str);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		ft_putstr(strt, len, str);
	}
	else
		ft_putstr(strt, len, str);
}
