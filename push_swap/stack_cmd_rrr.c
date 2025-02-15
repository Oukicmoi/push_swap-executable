/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:18:54 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/06 19:40:41 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rrc(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	tmp = tmp->next;
	while ((tmp->next)->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_stack **stack_b)
{
	rrc(stack_b);
	write(1, "rrb\n", 4);
}

void	rra(t_stack **stack_a)
{
	rrc(stack_a);
	write(1, "rra\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrc(stack_b);
	rrc(stack_a);
	write(1, "rrr\n", 4);
}
