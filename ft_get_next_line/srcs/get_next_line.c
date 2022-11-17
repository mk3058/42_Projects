/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:41:37 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/17 23:10:46 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static int  length;
    int         read_size;
    int         req_size;
    char        *buff[BUFF_SIZE];
    char        *result;

    ft_bzero(buff, BUFF_SIZE);
    read_size = read(fd, buff, BUFF_SIZE)
    while (find_newline(buff) < BUFF_SIZE)
        req_size += find_newline(buff);
    req_size += 

}

int find_newline(char *buff)
{
    int i;

    i = -1;
    while (++i < BUFF_SIZE)
        if (buff[i] == '\n')
            return (i);
    return (-1);
}