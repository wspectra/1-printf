/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:14:10 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/29 19:14:13 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_zero(t_strt *strt, int len)
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

void	ft_put_space(t_strt *strt, int len)
{
	int n;

	if (strt->type == 'p')
		strt->width = strt->width - 2;
	if (strt->type == '%' || strt->type == 'c' || strt->type == 's')
		strt->precision = -1;
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

void	ft_put_prec(t_strt *strt, int len)
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

void	ft_putchar(unsigned long int n, char type)
{
	if (type == 0)
	{
		write(1, &n, 1);
		return ;
	}
	if (n < 10)
		n = n + 48;
	else if (type == 'X')
		n = n + 55;
	else if (type == 'x' || type == 'p' )
		n = n + 87;
	write(1, &n, 1);
}

void	ft_putnbr(unsigned long int n, char type)
{
	unsigned long int div;

	if (type == 'x' || type == 'X' || type == 'p')
		div = 16;
	else
		div = 10;
	if (n >= div)
	{
		ft_putnbr(n / div, type);
		ft_putchar((n % div), type);
	}
	else
		ft_putchar(n, type);
}

int		ft_len_numb(unsigned long n, char type)
{
	int size;
	unsigned long int div;

	size = 0;
	if (type == 'x' || type == 'X' || type == 'p')
		div = 16;
	else
		div = 10;

	while (n >= div)
	{
		size++;
		n = n / div;
	}
	return (size + 1);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*s2;

	a = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * a + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, (a + 1));
	return (s2);
}

void	ft_putstr(t_strt *strt, int len, char *str)
{
	int i;

	i = 0;
	while (len > 0)
	{
		ft_putchar(str[i], 0);
		len--;
		i++;
		strt->count++;
	}
}