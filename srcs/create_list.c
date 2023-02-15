/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:03:35 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 14:38:35 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* Ici on cree la liste */

static void	ft_clean_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ft_simple_fill(t_list **new, char **av, int ac)
{
	int	i;

	i = 0;
	if (!ft_simple_arg_check(ac, av))
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (++i < ac)
		ft_lstadd_back(new, ft_lstnew(ft_atoi(av[i])));
}

static void	ft_spl_fill(t_list **new, char **spl)
{
	int	i;

	i = -1;
	if (!ft_spl_arg_check(spl))
		ft_printf("Error\n");
	else
	{
		while (spl[++i])
			ft_lstadd_back(new, ft_lstnew(ft_atoi(spl[i])));
	}
}

t_list	*ft_create_lst(int ac, char **av)
{
	char	**spl;
	t_list	*new;

	new = NULL;
	if (ac > 2)
		ft_simple_fill(&new, av, ac);
	else if (ac == 2)
	{
		spl = ft_split(av[1], ' ');
		if (!spl)
			return (NULL);
		ft_spl_fill(&new, spl);
		ft_clean_split(spl);
	}
	if (!new)
		return (NULL);
	ft_bigger_sorted_lst(&new);
	ft_index_lst(&new);
	return (new);
}
