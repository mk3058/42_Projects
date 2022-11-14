/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:08 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/14 10:32:59 by minkyu           ###   ########.fr       */
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
	int		flag_minus;
	int		flag_plus;
	int		flag_blank;
	int		flag_sharp;
	int		flag_zero;
	int		width;
	int		precision;
	char	specifier;
}	t_field;

void	field_parser(const char *format, int *index, t_field *field);
int		ft_putstr(char *s);
int		print_va(va_list *va, t_field *field);
int		format_parser(const char *format, va_list va);
int		ft_printf(const char *format, ...);
int		addr_to_hex(void *addr);
int	integer_to_hex(unsigned int num, t_field *field);
int		print_int(long long n, t_field *field);
void	ft_bzero(void *s, size_t n);
int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
char	*my_itoa(long long n);
int	print_signed_int(int n);
int	print_unsigned_int(unsigned int n);
int	ft_putstr_n(char *s, int n);

int	find_len(va_list va, t_field *field);
int	ft_hexlen(size_t input, t_field *field);
int str_to_str(char *result, t_field *field, char *input, int valid_width);
int char_to_str(char *result, t_field *field, char input, int valid_width);
int addr_to_str(char *result, t_field *field, void *input, int valid_width);
int integer_to_str(char *result, t_field *field, unsigned int input, int valid_width);
int    nbr_to_str(char *result, t_field *field, long long input, int valid_width);

#endif