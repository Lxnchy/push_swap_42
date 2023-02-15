/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:55:54 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 00:24:06 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_search(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != lst)
	{
		if (!tmp->sorted)
			return (1);
		tmp = tmp->next;
	}
	if (!tmp->sorted)
		return (1);
	return (0);
}

void	ft_push(t_list **a, t_list **b)
{
	while (ft_search(*a))
	{
		if (!(*a)->sorted)
		{
			push(a, b);
			ft_printf("pb\n");
		}
		else
		{
			while ((*a)->sorted)
			{
				rotate(a);
				ft_printf("ra\n");
			}
		}
	}
}

void	ft_midpush(t_list **a, t_list **b)
{
	int	middle;

	middle = ft_middle(*a);
	while (ft_lst_first_min(*a, middle) >= 0 && ft_lstsize(*a) > 3)
	{
		if ((*a)->x <= middle)
		{
			push(a, b);
			ft_printf("pb\n");
		}
		else if (ft_lst_first_min(*a, middle) < ft_lstsize(*a) / 2)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else if (ft_lst_first_min(*a, middle) >= ft_lstsize(*a) / 2)
		{
			r_rotate(a);
			ft_printf("rra\n");
		}
	}
	if (ft_lstsize(*a) > 3)
		ft_midpush(a, b);
}

void	ft_chunk_push(t_list **a, t_list **b, int size, int chunk_size)
{
	static int	i = 1;
	int			chunk;

	chunk = i * size / chunk_size;
	while (ft_lst_first_min(*a, chunk) >= 0 && ft_lstsize(*a) > 3)
	{
		if ((*a)->x <= chunk)
		{
			push(a, b);
			ft_printf("pb\n");
		}
		else if (ft_lst_first_min(*a, chunk) < ft_lstsize(*a) / 2)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else if (ft_lst_first_min(*a, chunk) >= ft_lstsize(*a) / 2)
		{
			r_rotate(a);
			ft_printf("rra\n");
		}
	}
	i++;
	if (ft_lstsize(*a) > 3)
		ft_chunk_push(a, b, size, chunk_size);
}
