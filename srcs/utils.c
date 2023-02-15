/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:30:32 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/13 17:51:03 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* Ici quelques fonctions banales, certaines
sont a supprimer si elles deviennent inutiles */

void	ft_lstprint(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp->next != lst)
	{
		ft_printf("%i\n", temp->x);
		temp = temp->next;
	}
	ft_printf("%i\n", temp->x);
}

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*tmp;
	t_list	*new;

	tmp = lst;
	new = NULL;
	while (tmp)
	{
		ft_lstadd_back(&new, ft_lstnew(tmp->x));
		tmp = tmp->next;
	}
	return (new);
}

int	ft_lstsorted(t_list *lst)
{
	t_list	*temp;
	int		min;
	int		i;

	if (!lst)
		return (1);
	temp = lst;
	i = 0;
	while (++i < ft_lstsize(lst))
	{
		min = temp->x;
		temp = temp->next;
		if (min > temp->x)
			return (0);
	}
	return (1);
}
