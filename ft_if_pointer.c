/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:35 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/28 21:33:36 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lenpointer(unsigned long int n)
{
	int size;

	size = 0;
	while (n >= 16)
	{
		size++;
		n = n / 16;
	}
	return (size + 1);
}

void	ft_if_pointer(t_strt *strt)
{
	unsigned long int	nb;
	int			len;

	nb = va_arg(strt->ap, unsigned long int);
	len = ft_lenpointer(nb);
	if (strt->minus && strt->width > 0)
	{
		write(1, "0x", 2);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->precision == -1)
	{
		ft_put_zero(strt, len);
		write(1, "0x", 2);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		write(1, "0x", 2);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	else
	{
		write(1, "0x", 2);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	strt->count  = strt->count + len + 2;
}
