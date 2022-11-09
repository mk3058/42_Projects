/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:13:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 20:29:25 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	tmp;
	t_list	*result;
	t_list	*new_list;

	tmp = lst;
	result = 0;
	if (lst == 0)
		return (0);
	while (1)
	{
		new_list = ft_lstnew(f(tmp -> content));
		if (new_list == 0)
			return (0);
		if (!tmp -> next)
			break ;
		if (result)
			ft_lstadd_back(&result, new_list);
		else
			result = new_list;
		tmp = tmp -> next;
	}
	return (result);
}
