/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instruct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:18:30 by quvan-de          #+#    #+#             */
/*   Updated: 2024/05/27 13:19:21 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	ft_r(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list **stack_a)
{
	ft_r(stack_a);
}

void	rb(t_list **stack_b)
{
	ft_r(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
}
