/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:08 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 13:37:55 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_field
{
	char	*flag;
	int		width;
	int		precision;
	char	specifier;
}	t_field;

int		ft_putstr(char *s);
int		print_va(va_list va, char specifier, char *field);
int		format_parser(const char *format, va_list va);
int		ft_printf(const char *format, ...);
int		addr_to_hex(void *addr);
int		integer_to_hex(unsigned int num, char specifier);
int		print_signed_int(int n);
int		print_unsigned_int(unsigned int n);
void	ft_bzero(void *s, size_t n);
int		ft_putchar(char c);
size_t	ft_strlen(const char *s);

#endif