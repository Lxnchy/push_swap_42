/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:19:26 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 13:51:42 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	*ft_create_tab(t_list *lst)
{
	int		*tab;
	int		i;
	t_list	*tmp;

	tab = ft_calloc(ft_lstsize(lst), sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	tmp = lst;
	while (++i < ft_lstsize(lst))
	{
		tab[i] = tmp->x;
		tmp = tmp->next;
	}
	return (tab);
}

void	ft_sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
	}
}

int	ft_middle(t_list *lst)
{
	int	*tab;
	int	middle;

	tab = ft_create_tab(lst);
	if (!tab)
		return (0);
	ft_sort_tab(tab, ft_lstsize(lst));
	middle = tab[ft_lstsize(lst) / 2];
	return (free(tab), middle);
}

void	ft_index_lst(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		*tab;

	j = -1;
	tmp = *lst;
	tab = ft_create_tab(*lst);
	if (!tab)
		return ;
	ft_sort_tab(tab, ft_lstsize(*lst));
	while (++j < ft_lstsize(*lst))
	{
		i = -1;
		while (tab[++i] != tmp->x)
			;
		tmp->x = i;
		tmp = tmp->next;
	}
	free(tab);
}
