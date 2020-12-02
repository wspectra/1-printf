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

static void	ft_put_zero(t_strt *strt)
{
	int n;

	n = strt->width - 1;
	while (n > 0)
	{
		write(1, "0", 1);
		strt->count++;
		n--;
	}
}

static void	ft_put_space(t_strt *strt)
{
	int n;

	n = strt->width - 1;
	while (n > 0)
	{
		write(1, " ", 1);
		strt->count++;
		n--;
	}
}

void		ft_if_char(t_strt *strt)
{
	if (strt->width > 0)
	{
		if (strt->minus)
		{
			ft_printchar(strt);
			ft_put_space(strt);
		}
		else if (strt->zero)
		{
			ft_put_zero(strt);
			ft_printchar(strt);
		}
		else
		{
			ft_put_space(strt);
			ft_printchar(strt);
		}
	}
	else
	{
		ft_printchar(strt);
	}
}
