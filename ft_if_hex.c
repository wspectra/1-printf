/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:30 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/28 21:33:31 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lenhex(unsigned int n)
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

void	ft_if_hex(t_strt *strt)
{
	unsigned int	nb;
	int			len;

	nb = (unsigned int)va_arg(strt->ap, unsigned int);
	len = ft_lenhex(nb);
	if (strt->precision == 0 && nb == 0)
	{
		if (strt->width > 0)
		{
			write(1, " ", 1);
			ft_put_space(strt, len);
		}
		else
			return ;
	}
	else if (strt->minus && strt->width > 0)
	{

		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->precision == -1)
	{
		ft_put_zero(strt, len);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	else
	{
		ft_put_prec(strt, len);
		ft_putnbr(nb, strt->type);
	}
	strt->count  = strt->count + len;
}

