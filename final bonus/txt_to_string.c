/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:59:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/15 00:53:26 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int str_to_str(char *result, t_field *field, char *input)
{
    int     size;

    if(input == 0)
        input = "(null)";
    size = ft_strlen(input);
    if ((field -> precision) > -1 && (field -> precision) < size)
        ft_memcpy(result, input, (field -> precision));
    else
        ft_memcpy(result, input, size + 1);
    return (1);
}

int char_to_str(char *result, t_field *field, char input)
{
    result[0] = input;
    result[1] = '\0';
    return (1);
}