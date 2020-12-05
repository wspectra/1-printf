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

int		ft_len(int n)
{
	int size;

	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		size = 1;
		n = n * (-1);
	}
	else
		size = 0;
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	return (size + 1);
}

void	ft_if_int(t_strt *strt)
{
	long int			nb;
	int			len;
	int			minus;
	minus = 0;
	nb = (int)va_arg(strt->ap, int);
	len = ft_len(nb);
	if (strt->precision == 0 && nb == 0)
	{
		if (strt->width > 0)
		{
			write(1, " ", 1);
			strt->count++;
			ft_put_space(strt, len);
			return;
		}
		else
			return ;
	}
	if (nb < 0)
	{
		minus = 1;
		nb = -nb;
		if(strt->precision != -1)
			strt->precision++;
	}
	if (strt->minus && strt->width > 0)
	{
		if (minus == 1)
			write(1, "-", 1);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
		ft_put_space(strt, len);
	}
	else if (strt->zero == 1 && strt->precision == -1)
	{
		if (minus == 1)
			write(1, "-", 1);
		ft_put_zero(strt, len);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		if (minus == 1)
			write(1, "-", 1);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	else
	{
		if (minus == 1)
			write(1, "-", 1);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	if (minus == 1)
		strt->count  = strt->count++;
	strt->count = strt->count + len;
}

