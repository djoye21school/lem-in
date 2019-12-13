/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:58:49 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/10 12:34:26 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst != NULL && f != NULL)
	{
		new = f(lst);
		if (new != NULL && lst->next != NULL)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
