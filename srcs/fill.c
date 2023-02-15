/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:49:33 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 00:20:51 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_move_test(t_list *a, t_list *b, t_move **res)
{
	if (((*res)->b_move <= ft_lstsize(b) / 2)
		&& ((*res)->a_move <= ft_lstsize(a) / 2))
	{
		(*res)->todo = 0;
	}
	else if (((*res)->b_move > ft_lstsize(b) / 2)
		&& ((*res)->a_move <= ft_lstsize(a) / 2))
	{
		(*res)->b_move = ft_lstsize(b) - (*res)->b_move;
		(*res)->todo = 1;
	}
	else if (((*res)->b_move <= ft_lstsize(b) / 2)
		&& ((*res)->a_move > ft_lstsize(a) / 2))
	{
		(*res)->a_move = ft_lstsize(a) - (*res)->a_move;
		(*res)->todo = 2;
	}
	else if (((*res)->b_move > ft_lstsize(b) / 2)
		&& ((*res)->a_move > ft_lstsize(a) / 2))
	{
		(*res)->b_move = ft_lstsize(b) - (*res)->b_move;
		(*res)->a_move = ft_lstsize(a) - (*res)->a_move;
		(*res)->todo = 3;
	}
	(*res)->res = (*res)->b_move + (*res)->a_move;
}

static t_move	*ft_bm(t_list *a, t_list *b, t_move *(*f)(t_list *, t_list *))
{
	t_move	*moves;
	t_move	*best;
	t_move	*tmp;

	moves = (*f)(a, b);
	if (!moves)
		return (NULL);
	tmp = moves;
	best = moves;
	while (tmp)
	{
		ft_move_test(a, b, &tmp);
		if (tmp->res < best->res)
			best = tmp;
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_move));
	if (!tmp)
		return (NULL);
	tmp->a_move = best->a_move;
	tmp->b_move = best->b_move;
	tmp->res = best->res;
	tmp->todo = best->todo;
	ft_clean_move(&moves);
	return (tmp);
}

void	ft_fill_a(t_list **a, t_list **b)
{
	t_move	*best;

	while (*b)
	{
		if (ft_lst_max(*b) < ft_lst_min(*a))
			best = ft_bm(*a, *b, ft_min_search);
		else if (ft_lst_min(*b) > ft_lst_max(*a))
			best = ft_bm(*a, *b, ft_max_search);
		else
			best = ft_bm(*a, *b, ft_check);
		if (!best)
			return ;
		ft_domoves(a, b, best);
		free(best);
		push(b, a);
		ft_printf("pa\n");
	}
}
