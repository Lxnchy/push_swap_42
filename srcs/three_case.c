/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:20:13 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/13 17:43:04 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* Algo pour trier les listes de 3 elements */

static void	ft_first(t_list **lst, int one, int two, int three)
{
	if (one < two)
	{
		r_rotate(lst);
		ft_printf("rra\n");
	}
	else if (three > two)
	{
		rotate(lst);
		ft_printf("ra\n");
	}
	else if (one > two)
	{
		swap(lst);
		r_rotate(lst);
		ft_printf("sa\nrra\n");
	}
}

static void	ft_second(t_list **lst, int two, int three)
{
	if (three > two)
	{
		swap(lst);
		ft_printf("sa\n");
	}
	else if (two > three)
	{
		swap(lst);
		rotate(lst);
		ft_printf("sa\nra\n");
	}
}

void	ft_three_case(t_list **lst)
{
	int		elem_one;
	int		elem_two;
	int		elem_three;

	if (ft_lstsorted(*lst))
		return ;
	elem_one = (*lst)->x;
	elem_two = (*lst)->next->x;
	elem_three = (*lst)->next->next->x;
	if (elem_one > elem_three)
		ft_first(lst, elem_one, elem_two, elem_three);
	else
		ft_second(lst, elem_two, elem_three);
}
