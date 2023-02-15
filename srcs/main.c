/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:34:13 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 14:40:40 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_do(t_list **lst_a, t_list **lst_b)
{
	t_list	*a;
	t_list	*b;

	a = *lst_a;
	b = *lst_b;
	ft_midpush(&a, &b);
	if (!ft_lstsorted(a))
		ft_three_case(&a);
	ft_fill_a(&a, &b);
	while (a->x != ft_lst_min(a))
	{
		if (ft_lstind(a, ft_lst_min(a)) < ft_lstsize(a) / 2)
		{
			rotate(&a);
			ft_printf("ra\n");
		}
		else
		{
			r_rotate(&a);
			ft_printf("rra\n");
		}
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
	if (ft_lstsize(a) == 3 && !ft_lstsorted(a))
		ft_three_case(&a);
	else if (ft_lstsize(a) > 3 && !ft_lstsorted(a))
		ft_do(&a, &b);
	ft_clean_lst(&a);
	return (0);
}
