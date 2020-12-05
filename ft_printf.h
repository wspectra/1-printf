/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wspectra <wspectra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:33:47 by wspectra          #+#    #+#             */
/*   Updated: 2020/11/28 21:33:55 by wspectra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_strt
{
	int		minus;
	int 	zero;
	int		width;
	int 	precision;
	char	type;
	int		i;
	int 	count;
	va_list ap;
}			t_strt;

int		ft_printf(const char *, ...);
void	ft_parsing(const char *str, t_strt *strt);
void	ft_if_char(t_strt *strt);
void	ft_if_string(t_strt *strt);
void	ft_if_procent(t_strt *strt);
void	ft_if_pointer(t_strt *strt);
void	ft_if_int(t_strt *strt);
void	ft_if_uns_int(t_strt *strt);
void	ft_if_hex(t_strt *strt);
void	ft_put_zero(t_strt *strt, int len);


void	ft_if_else(t_strt *strt);
size_t	ft_strlen(const char *str);
int		ft_lenint(unsigned int n);
void	ft_putchar(char c);
void	ft_putnbr(long int n);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
