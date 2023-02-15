/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:59:47 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 00:10:52 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_lst_max(t_list *lst)
{
	t_list	*tmp;
	int		max;
	int		i;

	max = lst->x;
	tmp = lst;
	i = -1;
	while (++i < ft_lstsize(lst))
	{
		if (max <= tmp->x)
			max = tmp->x;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_lst_min(t_list *lst)
{
	t_list	*tmp;
	int		min;
	int		i;

	i = -1;
	min = lst->x;
	tmp = lst;
	while (++i < ft_lstsize(lst))
	{
		if (min >= tmp->x)
			min = tmp->x;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_lst_first_min(t_list *lst, int min)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = lst;
	while (++i < ft_lstsize(lst))
	{
		if (tmp->x < min)
			return (i);
		tmp = tmp->next;
	}
	return (-1);
}

int	ft_lst_first_max(t_list *lst, int max)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = lst;
	while (++i < ft_lstsize(lst))
	{
		if (tmp->x > max)
			return (i);
	}
	return (-1);
}
