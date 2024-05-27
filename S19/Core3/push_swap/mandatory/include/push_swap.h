/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:42:55 by quvan-de          #+#    #+#             */
/*   Updated: 2024/05/27 14:45:50 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libftplus/include/libft.h"
# include <limits.h>

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		a_size;
	int		b_size;
}		t_swap;

/* Sorting */
void	check_sort(t_swap	*tab);
int		check_sorting(t_list **stack_a);
int		check_sorting_a(t_list **stack_a, int count);
t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);
int		is_rev_sorted(t_swap	*tab);

/* Instructions **/
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack_b);
void	rra(t_list **stack_a);

/* Indexing */
void	add_index(t_list *lst);

/* Quick sort */
void	quick_sort(t_list **stack_a, t_list **stack_b, int count);

#endif
