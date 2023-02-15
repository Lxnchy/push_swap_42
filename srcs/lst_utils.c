/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:50:06 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 00:16:36 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* Methodes de t_list */

int	ft_lstind(t_list *lst, int x)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp->next != lst)
	{
		if (tmp->x == x)
			return (i);
		i++;
		tmp = tmp->next;
	}
	if (tmp->x == x)
		return (i);
	return (-1);
}

t_list	*ft_lstnew(int x)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->x = x;
	new->next = new;
	new->prev = new;
	new->sorted = 0;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*j;

	if (!lst)
		return (0);
	i = 1;
	j = lst;
	while (j->next != lst)
	{
		j = j->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*res;

	res = lst;
	while (res->next != lst)
		res = res->next;
	return (res);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->prev = ft_lstlast(*lst);
	ft_lstlast(*lst)->next = new;
	(*lst)->prev = new;
	new->next = *lst;
}
