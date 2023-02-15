/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:44:28 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/11 16:51:04 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* Methodes de t_move */

t_move	*ft_new_move(int a_move, int b_move)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	move->a_move = a_move;
	move->b_move = b_move;
	move->todo = -1;
	move->res = 0;
	move->next = NULL;
	return (move);
}

void	ft_move_addback(t_move **move, t_move *new)
{
	t_move	*tmp;

	tmp = *move;
	if (!(*move))
	{
		*move = new;
		return ;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

t_move	*ft_check(t_list *a, t_list *b)
{
	t_move	*res;
	t_list	*tmpa;
	t_list	*tmpb;
	int		i;
	int		j;

	res = NULL;
	tmpa = a;
	i = -1;
	while (++i < ft_lstsize(a))
	{
		j = -1;
		tmpb = b;
		while (++j < ft_lstsize(b))
		{
			if (tmpb->x < tmpa->x && tmpb->x > tmpa->prev->x)
				ft_move_addback(&res, ft_new_move(i, j));
			tmpb = tmpb->next;
		}
		tmpa = tmpa->next;
	}
	if (!res)
		return (NULL);
	return (res);
}

t_move	*ft_max_search(t_list *a, t_list *b)
{
	t_move	*res;

	res = ft_new_move(ft_lstind(a, ft_lst_max(a)), 0);
	if (!res)
		return (NULL);
	(void)b;
	return (res);
}

t_move	*ft_min_search(t_list *a, t_list *b)
{
	t_move	*res;

	res = ft_new_move(ft_lstind(a, ft_lst_min(a)), 0);
	if (!res)
		return (NULL);
	(void)b;
	return (res);
}
