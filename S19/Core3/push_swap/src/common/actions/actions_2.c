/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:00:06 by quvan-de          #+#    #+#             */
/*   Updated: 2024/05/17 10:00:41 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common/common.h"

void	rev_rotate_a(t_mem *mem)
{
	put_bottom_to_top(&(mem->a));
	if (mem->print)
		ft_putstr("rra");
}

void	rev_rotate_b(t_mem *mem)
{
	put_bottom_to_top(&(mem->b));
	if (mem->print)
		ft_putstr("rrb");
}

void	rev_rotate_b_a(t_mem *mem)
{
	put_bottom_to_top(&(mem->b));
	put_bottom_to_top(&(mem->a));
	if (mem->print)
		ft_putstr("rrr");
}

void	rotate_a(t_mem *mem)
{
	put_top_to_bottom(&(mem->a));
	if (mem->print)
		ft_putstr("ra");
}

void	rotate_b(t_mem *mem)
{
	put_top_to_bottom(&(mem->b));
	if (mem->print)
		ft_putstr("rb");
}
