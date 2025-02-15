/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_pp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:17:35 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/06 19:42:03 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	pa(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*current;
	t_stack	*temp;

	if (!*pile_b)
		return ;
	current = *pile_b;
	temp = (*pile_b)->next;
	current->next = *pile_a;
	*pile_a = current;
	*pile_b = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*current;
	t_stack	*temp;

	if (!*pile_a)
		return ;
	current = *pile_a;
	temp = (*pile_a)->next;
	current->next = *pile_b;
	*pile_b = current;
	*pile_a = temp;
	write(1, "pb\n", 3);
}
