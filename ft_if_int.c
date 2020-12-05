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

void	ft_if_int(t_strt *strt)
{
	long int			nb;
	int			len;
	int			minus;
	minus = 0;
	len = 0;
	nb = (int)va_arg(strt->ap, int);
	if (strt->precision == 0 && nb == 0)
	{
		if (strt->width > 0)
		{
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
		len = 1;
		if(strt->precision != -1)
			strt->precision++;
	}
	len = len + ft_len_numb(nb, strt->type);
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

