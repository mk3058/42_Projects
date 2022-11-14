/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:59:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/14 20:43:15 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int str_to_str(char *result, t_field *field, char *input, int valid_width)
{
    int     i;
    int     size;

    i = 0;
    if(input == 0)
        input = "(null)";
    size = ft_strlen(input);
    if ((field -> specifier != 's') && (field -> precision) < size)
        if(field -> precision > -1)
           //field -> precision = -1;
    if (valid_width)
    {
        if (input[0] == '-' && field -> precision == -1)
        {
            result[0] = '-';
            input++;
            i++;
            size--;
        }
        if (!(field -> flag_minus))
            i = field -> width - size;
        ft_memcpy(result + i, input, size);
    }
    else
    {
        ft_memcpy(result, input, size);
        result[size] = '\0';
    }
    return (1);
}

#include <stdio.h>
int char_to_str(char *result, t_field *field, char input, int valid_width)
{
    int     i;

    i = 1;
    if (valid_width)
    {
        if (!(field -> flag_minus))
            i = field -> width;
        result[i - 1] = input;
    }
    else
        result[0] = input;
    
    return (1);
}