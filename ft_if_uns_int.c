/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:41 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/28 21:33:42 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	if(strt->precision != -1 && strt->precision > len)
		n = strt->width - strt->precision;
	else
		n = strt->width - len;
	while (n > 0)
	{
		write(1, " ", 1);
		strt->count++;
		n--;
	}
}

static void	ft_put_prec(t_strt *strt, int len)
{
	if (len < strt->precision && strt->precision != -1)
	{
		while (len != strt->precision)
		{
			write(1, "0", 1);
			strt->count++;
			len++;
		}
	}
}


void	ft_if_uns_int(t_strt *strt)
{
	unsigned int	nb;
	int			len;

	nb = (unsigned int)va_arg(strt->ap, unsigned int);
	len = ft_lenint(nb);
	if (strt->minus && strt->width > 0)
	{

		ft_put_prec(strt, len);
		ft_putnbr(nb);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->precision == -1)
	{
		ft_put_zero(strt, len);
		ft_put_prec(strt, len);
		ft_putnbr(nb);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		ft_put_prec(strt, len);
		ft_putnbr(nb);
	}
	else
	{
		ft_put_prec(strt, len);
		ft_putnbr(nb);
	}
	strt->count  = strt->count + len;
}
