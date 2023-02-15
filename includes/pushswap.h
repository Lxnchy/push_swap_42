/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:39:40 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/15 13:09:33 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/includes/libft.h"

/* Structs
list : stack
move : liste de mouvements possibles */

typedef struct s_move
{
	int				res;
	int				todo;
	int				a_move;
	int				b_move;
	struct s_move	*next;
}	t_move;

typedef struct s_list
{
	int				x;
	int				sorted;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_move	*ft_new_move(int a_move, int b_move);
void	ft_move_addback(t_move **move, t_move *new);
t_move	*ft_check(t_list *a, t_list *b);
t_move	*ft_max_search(t_list *a, t_list *b);
t_move	*ft_min_search(t_list *a, t_list *b);

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int x);
int		ft_lstsize(t_list *lst);

/* Moves */

void	push(t_list **a, t_list **b);
void	rotate(t_list **lst);
void	r_rotate(t_list	**lst);
void	swap(t_list	**lst);

/* Parsing */

t_list	*ft_create_lst(int ac, char **av);

/* Sorted element */

void	ft_bigger_sorted_lst(t_list **a);

/* First push */

void	ft_push(t_list **a, t_list **b);
void	ft_midpush(t_list **a, t_list **b);
void	ft_chunk_push(t_list **a, t_list **b, int size, int chunk_size);

/* Utils */

void	ft_lstprint(t_list *lst);
t_list	*ft_lstdup(t_list *lst);
int		ft_lstsorted(t_list *lst);

/* Three case */

void	ft_three_case(t_list **lst);

/* Value check */

int		ft_lst_max(t_list *lst);
int		ft_lst_min(t_list *lst);
int		ft_lstind(t_list *lst, int x);
int		ft_lst_first_min(t_list *lst, int min);
int		ft_lst_first_max(t_list *lst, int max);

/* Fill */

void	ft_domoves(t_list **a, t_list **b, t_move *best);
void	ft_fill_a(t_list **a, t_list **b);

/* Tab */

int		*ft_create_tab(t_list *lst);
int		ft_middle(t_list *lst);
void	ft_sort_tab(int *tab, int len);
void	ft_index_lst(t_list **lst);

/* Clean */

void	ft_clean_lst(t_list **lst);
void	ft_clean_move(t_move **move);

/* Parsing */
int		ft_simple_arg_check(int ac, char **av);
int		ft_spl_arg_check(char **spl);
void	ft_check_same(t_list **lst);

#endif