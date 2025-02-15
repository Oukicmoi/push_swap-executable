/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:11:04 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/06 19:05:20 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	emptyb(t_stack **stack_a, t_stack **stack_b)
{
	int	sort;
	int	valopti;

	sort = 0;
	while (*stack_b)
	{
		valopti = bigcost(stack_a, stack_b);
		midsort(stack_a, stack_b, valopti);
	}
}

void	midsort(t_stack **stack_a, t_stack **stack_b, int b)
{
	int	i;
	int	tb;
	int	ta;

	tb = ft_stsize(stack_b);
	ta = ft_stsize(stack_a);
	i = rchfval(stack_a, b);
	if (i == 0)
	{
		while (ft_intindex(stack_b, b) != 0)
		{
			if (ft_intindex(stack_b, b) <= tb / 2 && ft_intindex(stack_b,
					b) != 0)
				rb(stack_b);
			else if (ft_intindex(stack_b, b) > tb / 2)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else
		ltlsort(stack_a, stack_b, rchfval(stack_a, b), b);
}

void	ltlsort(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	int	i;

	i = 0;
	while (ft_intindex(stack_a, a) != 0 || ft_intindex(stack_b, b) != 0)
		ltlsortif(stack_a, stack_b, a, b);
	pa(stack_a, stack_b);
}

void	ltlsortif(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	int	tb;
	int	ta;

	tb = ft_stsize(stack_b);
	ta = ft_stsize(stack_a);
	if (ft_intindex(stack_b, b) <= tb / 2 && ft_intindex(stack_a, a) <= ta / 2
		&& ft_intindex(stack_b, b) != 0 && ft_intindex(stack_a, a) != 0)
		rr(stack_a, stack_b);
	else if (ft_intindex(stack_b, b) <= tb / 2 && ft_intindex(stack_b, b) != 0)
		rb(stack_b);
	else if (ft_intindex(stack_a, a) <= ta / 2 && ft_intindex(stack_a, a) != 0)
	{
		ra(stack_a);
	}
	if (ft_intindex(stack_b, b) > tb / 2 && ft_intindex(stack_a, a) > ta / 2
		&& ft_intindex(stack_b, b) != 0 && ft_intindex(stack_a, a) != 0)
		rrr(stack_a, stack_b);
	else if (ft_intindex(stack_b, b) > tb / 2)
	{
		rrb(stack_b);
	}
	else if (ft_intindex(stack_a, a) > ta / 2)
	{
		rra(stack_a);
	}
}
