/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:41 by wspectra          #+#    #+#             */
/*   Updated: 2020/12/06 17:16:00 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_uns_int(t_strt *strt)
{
	unsigned int	nb;
	int				len;

	nb = (unsigned int)va_arg(strt->ap, unsigned int);
	len = ft_len_numb(nb, strt->type);
	if (strt->precision == 0 && nb == 0)
	{
		if (strt->width > 0)
		{
			write(1, " ", 1);
			strt->count++;
			ft_put_space(strt, len);
			return ;
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
	else if (strt->zero == 1 && strt->precision <= -1)
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
	strt->count = strt->count + len;
}
