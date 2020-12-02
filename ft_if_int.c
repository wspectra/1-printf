///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_if_int.c                                        :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2020/11/28 21:33:32 by wspectra          #+#    #+#             */
///*   Updated: 2020/11/28 21:33:33 by wspectra         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "ft_printf.h"
//
//int		ft_lenint(int n)
//{
//	int size;
//
//	size = 0;
//	if (n < 0)
//		n = n * (-1);
//	while (n >= 10)
//	{
//		size++;
//		n = n / 10;
//	}
//	return (size + 1);
//}
//void	ft_putchar(char c)
//{
//	write(1, &c, 1);
//}
//void	ft_putnbr(int n)
//{
//	if (n == -2147483648)
//	{
//		write(1,"-2147483648", 11);
//		return ;
//	}
//	if (n < 0)
//	{
//		write(1, "-", 1);
//		n = n * (-1);
//	}
//	if (n > 9)
//	{
//		ft_putnbr(n / 10);
//		ft_putchar((n % 10) + 48);
//	}
//	else
//		ft_putchar((n + 48));
//}
//static void	ft_put_prec(t_strt *strt, int len)
//{
//		if (len < strt->precision && strt->precision != -1)
//		{
//			while (len != strt->precision)
//			{
//				write(1, "0", 1);
//				strt->count++;
//				strt->precision--;
//			}
//		}
//}
//
//static void	ft_put_zero(t_strt *strt, int len)
//{
//	int n;
//
//	n = strt->width - len;
//	while (n > 0)
//	{
//		write(1, "0", 1);
//		strt->count++;
//		n--;
//	}
//}
//
//static void	ft_put_space(t_strt *strt, int len)
//{
//	int n;
//
//	n = strt->width - len;
//	while (n > 0)
//	{
//		write(1, " ", 1);
//		strt->count++;
//		n--;
//	}
//}
//
//void	ft_if_int(t_strt *strt)
//{
//	long int	nb;
//	int			len;
//
//	nb = (int)va_arg(strt->ap, int);
//	len = ft_lenint(nb);
//	if (nb < 0)
//	{
//		write(1, "-", 1);
//		nb = nb * (-1);
//	}
//
//	if (strt->minus && strt->width > 0)
//	{
//		ft_put_prec(strt, len);
//		ft_put_space(strt, len);
//	}
//	else if (strt->zero && strt->width > 0)
//	{
//		ft_put_zero(strt, len);
//		ft_put_prec(strt, len);
//	}
//	else if (strt->width > 0)
//	{
//		ft_put_space(strt, len);
//		ft_put_prec(strt, len);
//	}
//	else
//		ft_put_prec(strt, len);
//		ft_putnbr(nb);
//}
