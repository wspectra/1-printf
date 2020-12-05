/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_procent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:16:10 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/30 21:16:14 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printchar(t_strt *strt)
{
	write(1, "%", 1);
	strt->count++;
}

void	ft_if_procent(t_strt *strt)
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
