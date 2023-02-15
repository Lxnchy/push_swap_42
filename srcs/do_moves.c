/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:15:37 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/14 16:15:22 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_finish_a(t_list **a, int nb, int todo)
{
	while (nb)
	{
		if (todo == 0 || todo == 1)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else
		{
			r_rotate(a);
			ft_printf("rra\n");
		}
		nb--;
	}
}

static void	ft_finish_b(t_list **b, int nb, int todo)
{
	while (nb)
	{
		if (todo == 0 || todo == 2)
		{
			rotate(b);
			ft_printf("rb\n");
		}
		else
		{
			r_rotate(b);
			ft_printf("rrb\n");
		}
		nb--;
	}
}

static void	ft_perfect(t_list **a, t_list **b, t_move *best)
{
	while (best->a_move && best->b_move)
	{
		if (!best->todo)
		{
			rotate(a);
			rotate(b);
			ft_printf("rr\n");
		}
		else if (best->todo == 3)
		{
			r_rotate(a);
			r_rotate(b);
			ft_printf("rrr\n");
		}
		best->a_move--;
		best->b_move--;
	}
}

static void	ft_imperfect(t_list **a, t_list **b, t_move *best)
{
	while (best->a_move && best->b_move)
	{
		if (best->todo == 1)
		{
			rotate(a);
			r_rotate(b);
			ft_printf("ra\nrrb\n");
		}
		else if (best->todo == 2)
		{
			r_rotate(a);
			rotate(b);
			ft_printf("rra\nrb\n");
		}
		best->a_move--;
		best->b_move--;
	}
}

/* Ici on effectue les mouvements rra/rb / ra/rrb / rrr / rr
pour amener face a face les deux elements correspondants pour push */

void	ft_domoves(t_list **a, t_list **b, t_move *best)
{
	if ((!best->todo || best->todo == 3) && ft_lstsize(*b) > 1)
		ft_perfect(a, b, best);
	else if ((best->todo == 1 || best->todo == 2) && ft_lstsize(*b) > 1)
		ft_imperfect(a, b, best);
	if (best->a_move)
		ft_finish_a(a, best->a_move, best->todo);
	else if (best->b_move && ft_lstsize(*b) > 1)
		ft_finish_b(b, best->b_move, best->todo);
}
