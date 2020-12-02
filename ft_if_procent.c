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
void	ft_if_procent(t_strt *strt)
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
