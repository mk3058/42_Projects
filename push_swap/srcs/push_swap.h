/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:28 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/29 18:17:39 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"
# include "./libft/libft.h"
# include <stdlib.h> /////////////
# include <stdio.h> /////////////////////////

void	get_arguments(int argc, char **argv, t_deque *a, t_deque *b);
void	exit_err(t_deque *a, t_deque *b);

#endif