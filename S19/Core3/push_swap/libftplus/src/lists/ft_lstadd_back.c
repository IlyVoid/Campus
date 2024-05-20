/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:58:26 by quvan-de          #+#    #+#             */
/*   Updated: 2024/05/20 13:01:23 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n_new)
{
	if (!lst || !n_new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = n_new;
	else
		*lst = n_new;
}
