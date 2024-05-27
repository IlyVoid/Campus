/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:26:29 by quvan-de          #+#    #+#             */
/*   Updated: 2024/05/27 14:31:03 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3nbr(t_swap *tab)
{
	t_list	*last;

	if (check_sorting(&tab->stack_a))
		return ;
	last = ft_lstlast(tab->stack_a);
	if (is_rev_sorted(tab))
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}
	else if (tab->stack_a->content < last ->content
		&& tab->stack_a->next->content < last->content)
		sa(&tab->stack_a);
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content < last->content)
		ra(&tab->stack_a);
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content > last->content)
	{
		sa(&tab->stack_a);
		ra(&tab->stack_a);
	}
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content > last->content)
		rra(&tab->stack_a);
}

void	sort_5nbr(t_swap *tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	while (len--)
	{
		if (tab->stack_a->index == 0 || tab->stack_a->index == 1)
			pb(&tab->stack_a, &tab->stack_b);
		else
			ra(&tab->stack_a);
	}
	sort_3nbr(tab);
	pa(&tab->stack_a, &tab->stack_b);
	pa(&tab->stack_a, &tab->stack_b);
	if (tab->stack_a->content > tab->stack_a->next->content)
		sa(&tab->stack_a);
}

void	check_sort(t_swap *tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	if (check_sorting(&tab->stack_a))
		return ;
	if (len == 2)
	{
		if (tab->stack_a->content > tab->stack_a->next->content)
			sa(&tab->stack_a);
	}
	else if (len == 3)
		sort_3nbr(tab);
	else if (len == 5)
		sort_5nbr(tab);
	else
		quick_sort(&tab->stack_a, &tab->stack_b, ft_lstsize(tab->stack_a));
}
