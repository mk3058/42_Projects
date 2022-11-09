/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:10:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 20:13:10 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	tmp;

	tmp = lst;
	while (1)
	{
		f((*tmp).content);
		if (!tmp -> next)
			break ;
		tmp = tmp -> next;
	}
}
