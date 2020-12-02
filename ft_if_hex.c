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

void	ft_putchar_hex(unsigned int n, char c)
{
	if (n < 10)
		n = n + 48;
	else if (c == 'X')
		n = n + 55;
	else if (c == 'x')
		n = n + 87;
	write(1, &n, 1);

}

void	ft_put_hex(unsigned int n, char c)
{
	if (n > 16)
	{
		ft_put_hex(n / 16, c);
		ft_putchar_hex((n % 16), c);
	}
	else
		ft_putchar_hex(n, c);
}

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
	if (len < strt->precision && strt->precision >= 0)
	{
		while (len != strt->precision)
		{
			write(1, "0", 1);
			strt->count++;
			len++;
		}
	}
}


void	ft_if_hex(t_strt *strt)
{
	unsigned int	nb;
	int			len;

	nb = (unsigned int)va_arg(strt->ap, unsigned int);
//	if (!nb)
//	{
//		len = 0;
//		ft_put_space(strt, len);
//	}
	len = ft_lenhex(nb);
	if (strt->minus && strt->width > 0)
	{

		ft_put_prec(strt, len);
		ft_put_hex(nb, strt->type);
		ft_put_space(strt, len);
	}
	else if (strt->zero && strt->precision == -1)
	{
		ft_put_zero(strt, len);
		ft_put_prec(strt, len);
		ft_put_hex(nb, strt->type);
	}
	else if (strt->width > 0)
	{
		ft_put_space(strt, len);
		ft_put_prec(strt, len);
		ft_put_hex(nb, strt->type);
	}
	else
	{
		ft_put_prec(strt, len);
		ft_put_hex(nb, strt->type);
	}
	strt->count  = strt->count + len;
}

