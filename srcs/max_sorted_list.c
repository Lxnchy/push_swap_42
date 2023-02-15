/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sorted_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:06:23 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 13:47:54 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_sorted_size(t_list *lst)
{
	int		cur;
	int		i;
	int		j;
	t_list	*tmp;

	if (!lst)
		return (-1);
	tmp = lst;
	cur = tmp->x;
	i = 0;
	j = -1;
	while (++j < ft_lstsize(lst))
	{
		if (cur <= tmp->x)
		{
			i++;
			cur = tmp->x;
		}
		tmp = tmp->next;
	}
	return (i);
}

static int	ft_max_size(int *sizes)
{
	int	i;
	int	max;
	int	cnt;

	i = -1;
	max = 0;
	cnt = 0;
	while (sizes[++i])
	{
		if (sizes[i] > max)
		{
			max = sizes[i];
			cnt = i;
		}
	}
	return (free(sizes), cnt);
}

static void	ft_is_sorted(t_list **lst, int i)
{
	int		j;
	int		cur;
	t_list	*tmp;

	if (i < 0)
		return ;
	tmp = *lst;
	j = -1;
	while (++j < i)
		tmp = tmp->next;
	j = -1;
	cur = tmp->x;
	while (++j < ft_lstsize(tmp))
	{
		if (cur <= tmp->x)
		{
			tmp->sorted = 1;
			cur = tmp->x;
		}
		tmp = tmp->next;
	}
}

void	ft_bigger_sorted_lst(t_list **a)
{
	t_list	*tmp;
	int		*sizes;
	int		i;

	i = 0;
	tmp = *a;
	sizes = ft_calloc(ft_lstsize(*a) + 1, sizeof(int));
	if (!sizes)
		return ;
	while (tmp->next != *a)
	{
		sizes[i] = ft_sorted_size(tmp);
		i++;
		tmp = tmp->next;
	}
	sizes[i] = ft_sorted_size(tmp);
	i++;
	ft_is_sorted(a, ft_max_size(sizes));
}
