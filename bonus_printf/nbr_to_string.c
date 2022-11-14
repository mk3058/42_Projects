/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:25:57 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/14 09:35:07 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    nbr_to_str(char *result, t_field *field, long long input, int valid_width)
{
    char    *nbr_str;

    nbr_str = my_itoa(input);
    if (nbr_str == 0)
        return(-1);
    str_to_str(result, field, nbr_str, valid_width);
    free(nbr_str);
    return (1);
}