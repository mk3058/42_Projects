/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:59:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/14 10:41:31 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int str_to_str(char *result, t_field *field, char *input, int valid_width)
{
    int     i;
    int     size;

    i = 0;
    if(input == 0)
    {
        ft_memcpy(result, "(null)", 6);
        return (1);
    }
    size = ft_strlen(input);
    if ((field -> precision) > -1 && (field -> precision) < size)
        size = (field -> precision);
    if (valid_width)
    {
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

int char_to_str(char *result, t_field *field, char input, int valid_width)
{
    int     i;
    int     size;

    i = 0;
    size = 1;
    if (valid_width)
    {
        if (!(field -> flag_minus))
            i = field -> width;
        ft_memcpy(result + i, &input, size);
    }
    else
        result[0] = input;
    return (1);
}