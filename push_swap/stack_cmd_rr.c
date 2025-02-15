/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:17:40 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/06 15:41:02 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	r(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = (*stack_a);
	first = (*stack_a)->next;
	tmp = first;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = last;
	last->next = NULL;
	*stack_a = first;
}

void	ra(t_stack **stack_a)
{
	r(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	r(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_b, t_stack **stack_a)
{
	r(stack_a);
	r(stack_b);
	write(1, "rr\n", 3);
}
