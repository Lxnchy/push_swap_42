/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:47:49 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 13:48:30 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_minax_check(char *nb)
{
	if (ft_strlen(nb) == 10)
	{
		if (ft_isdigit(nb[0]))
		{
			if (nb[0] - 48 > 2)
				return (0);
		}
	}
	else if (ft_strlen(nb) == 11)
	{
		if (nb[1] - 48 > 2 || ft_isdigit(nb[0]))
			return (0);
	}
	return (1);
}

int	ft_simple_arg_check(int ac, char **av)
{
	char	*res;
	int		i;
	int		test;

	i = 0;
	while (++i < ac)
	{
		test = ft_atoi(av[i]);
		res = ft_itoa(test);
		if (ft_strncmp(av[i], res, ft_strlen(av[i])) || !ft_minax_check(av[i]))
			return (free(res), 0);
		free(res);
	}
	return (1);
}

int	ft_spl_arg_check(char **spl)
{
	char	*res;
	int		i;
	int		test;

	i = -1;
	while (spl[++i])
	{
		test = ft_atoi(spl[i]);
		res = ft_itoa(test);
		if (ft_strncmp(spl[i], res, ft_strlen(spl[i]))
			|| !ft_minax_check(spl[i]))
			return (free(res), 0);
		free(res);
	}
	return (1);
}

void	ft_check_same(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp_two;
	int		i;
	int		j;

	i = -1;
	tmp = *lst;
	while (++i < ft_lstsize(*lst))
	{
		j = -1;
		tmp_two = tmp->next;
		while (++j < ft_lstsize(*lst) - 1)
		{
			if (tmp_two->x == tmp->x)
			{
				ft_printf("Error\n");
				ft_clean_lst(lst);
				exit(1);
			}
			tmp_two = tmp_two->next;
		}
		tmp = tmp->next;
	}
}
