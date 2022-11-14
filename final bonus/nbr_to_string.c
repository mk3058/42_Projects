/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:25:57 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/15 01:17:38 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    nbr_to_str(char *result, t_field *field, long long input)
{
    char    *nbr_str;
    int     diff;

    nbr_str = my_itoa(input);
    diff = ft_strlen(result) - ft_strlen(nbr_str) + 1;
    if (nbr_str == 0)
        return(-1);
    result[0] = nbr_str[0];
    ft_memcpy(result + diff, nbr_str + 1, ft_strlen(nbr_str) - 1);
    free(nbr_str);
    return (1);
}
