/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:36:24 by wspectra          #+#    #+#             */
/*   Updated: 2020/12/02 18:36:29 by wspectra         ###   ########.fr       */
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

void	ft_if_int(t_strt *strt)
{
	unsigned int	nb;
	int			len;
	int			minus;
	minus = 0;
	nb = (int)va_arg(strt->ap, int);

	if (nb < 0)
	{
		minus = 1;
		nb = nb * (-1);
	}
	len = ft_lenint(nb);
	if (strt->minus && strt->width > 0)
	{
		if (minus == 1)
			write(1, "-", 1);
		ft_put_prec(strt, len);
		ft_putnbr(nb);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->precision >= 0)
	{
		ft_put_zero(strt, len);
		if (minus == 1)
			write(1, "-", 1);
		ft_put_prec(strt, len);
		ft_putnbr(nb);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		if (minus == 1)
			write(1, "-", 1);
		ft_put_prec(strt, len);
		ft_putnbr(nb);
	}
	else
	{
		if (minus == 1)
			write(1, "-", 1);
		ft_put_prec(strt, len);
		ft_putnbr(nb);
	}
	if (minus == 1)
		strt->count  = strt->count ++;
	strt->count  = strt->count + len;
}

