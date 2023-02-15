/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:45:14 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 14:47:24 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	ft_get_moves(t_list **a, t_list **b)
{
	char	*gnl;

	gnl = get_next_line(0);
	while (gnl)
	{
		ft_wich_rotate(gnl, a, b);
		free(gnl);
		gnl = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		return (1);
	a = ft_create_lst(ac, av);
	if (!a)
		return (1);
	b = NULL;
	ft_check_same(&a);
	ft_get_moves(&a, &b);
	if (b || !ft_lstsorted(a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_clean_lst(&a);
	ft_clean_lst(&b);
	return (0);
}
