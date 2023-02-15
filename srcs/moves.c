/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:43:21 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/08 17:15:07 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* Ici on implemente les mouvements permis */

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		ft_lstlast(*src)->next = (*src)->next;
		*src = (*src)->next;
		(*src)->prev = ft_lstlast(*src);
	}
	if (!*dst)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->prev = ft_lstlast(*dst);
		ft_lstlast(*dst)->next = tmp;
		tmp->next = *dst;
		(*dst)->prev = tmp;
	}
	*dst = tmp;
}

void	rotate(t_list **lst)
{
	(*lst) = (*lst)->next;
}

void	r_rotate(t_list	**lst)
{
	(*lst) = (*lst)->prev;
}

void	swap(t_list	**lst)
{
	int	tmp;

	tmp = (*lst)->x;
	(*lst)->x = (*lst)->next->x;
	(*lst)->next->x = tmp;
}
