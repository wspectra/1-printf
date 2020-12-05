/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:20 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/28 21:33:23 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printchar(t_strt *strt)
{
	unsigned char c;

	c = (unsigned char)va_arg(strt->ap, int);
	write(1, &c, 1);
	strt->count++;
}

void		ft_if_char(t_strt *strt)
{
	if (strt->width > 0)
	{
		if (strt->minus)
		{
			ft_printchar(strt);
			ft_put_space(strt, 1);
		}
		else if (strt->zero)
		{
			ft_put_zero(strt, 1);
			ft_printchar(strt);
		}
		else
		{
			ft_put_space(strt, 1);
			ft_printchar(strt);
		}
	}
	else
	{
		ft_printchar(strt);
	}
}
