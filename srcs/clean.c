/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:00:35 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/14 11:50:02 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_clean_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*to_free;
	int		i;
	int		size;

	i = -1;
	tmp = *lst;
	size = ft_lstsize(*lst);
	while (++i < size)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
}

void	ft_clean_move(t_move **move)
{
	t_move	*tmp;
	t_move	*to_free;

	tmp = *move;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
}
