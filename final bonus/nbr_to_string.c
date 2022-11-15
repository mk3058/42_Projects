/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:25:57 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/15 17:13:25 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int nbr_to_str(char *result, t_field *field, long long input)
{
    char    *nbr_str;
    int     diff;
    int     nbr_index;

    if (field -> precision == 0 && input == 0)
    {
        ft_memset(result, 0, 2);
        return (1);
    }
    nbr_str = my_itoa(input);
    diff = 0;
    nbr_index = 0;
    if (nbr_str == 0)
        return(-1);
    if (field -> specifier != 'u')
        result[0] = nbr_str[0];
    if (field -> precision > -1)
        diff = ft_strlen(result) - ft_strlen(nbr_str) + 1;
    else if (ft_strchr("di", field -> specifier) != 0)
        diff = 1;
    ft_memcpy(result + diff, nbr_str + 1, ft_strlen(nbr_str) - 1);
    free(nbr_str);
    return (1);
}
