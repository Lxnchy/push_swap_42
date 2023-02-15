/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:53:05 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 14:32:03 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	ft_wrong_move(char *move, t_list **a, t_list **b)
{
	ft_clean_lst(a);
	ft_clean_lst(b);
	ft_cleangnl(0);
	free(move);
	ft_printf("Error\n");
	exit(1);
}

static void	ft_wich_else(char *move, t_list **a, t_list **b)
{
	if (!ft_strncmp(move, "pa\n", ft_strlen(move)))
		push(b, a);
	else if (!ft_strncmp(move, "pb\n", ft_strlen(move)))
		push(a, b);
	else if (!ft_strncmp(move, "ss\n", ft_strlen(move)))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp(move, "sa\n", ft_strlen(move)))
		swap(a);
	else if (!ft_strncmp(move, "sb\n", ft_strlen(move)))
		swap(b);
	else
		ft_wrong_move(move, a, b);
}

void	ft_wich_rotate(char *move, t_list **a, t_list **b)
{
	if (ft_strlen(move) < 2)
		ft_wrong_move(move, a, b);
	if (!ft_strncmp(move, "rrr\n", ft_strlen(move)))
	{
		r_rotate(a);
		r_rotate(b);
	}
	else if (!ft_strncmp(move, "rra\n", ft_strlen(move)))
		r_rotate(a);
	else if (!strncmp(move, "rrb\n", ft_strlen(move)))
		r_rotate(b);
	else if (!strncmp(move, "rr\n", ft_strlen(move)))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(move, "ra\n", ft_strlen(move)))
		rotate(a);
	else if (!ft_strncmp(move, "rb\n", ft_strlen(move)))
		rotate(b);
	else
		ft_wich_else(move, a, b);
}
