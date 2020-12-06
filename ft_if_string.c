/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:38 by wspectra          #+#    #+#             */
/*   Updated: 2020/12/06 18:08:12 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_no_str(t_strt *strt, int bytes)
{
	if (bytes < 6 && bytes >= 0)
	{
		strt->count = strt->count + bytes;
		write(1, "(null)", bytes);
	}
	else
	{
		strt->count = strt->count + 6;
		write(1, "(null)", 6);
	}
}

void		ft_if_string(t_strt *strt)
{
	char	*str;
	int		len;
	int		bytes;

	str = (char*)va_arg(strt->ap, char*);
	bytes = strt->precision;
	len = ft_strlen(str, strt->precision);
	if (len > strt->precision && strt->precision >= 0)
		len = strt->precision;
	if (strt->minus && strt->width > 0)
	{
		if (!str)
		{
			ft_no_str(strt, bytes);
		}
		else
			ft_putstr(strt, len, str);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->width > 0)
	{
		ft_put_zero(strt, len);
		if (!str)
		{
			ft_no_str(strt, bytes);
		}
		else
			ft_putstr(strt, len, str);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		if (!str)
		{
			ft_no_str(strt, bytes);
		}
		else
			ft_putstr(strt, len, str);
	}
	else
	{
		if (!str)
		{
			ft_no_str(strt, bytes);
		}
		else
			ft_putstr(strt, len, str);
	}
}
