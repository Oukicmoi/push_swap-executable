/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:20:31 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 20:57:53 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	allthree1(t_stack **stack_a, t_stack **stack_b)
{
	int	valopti;
	int	i;

	i = 0;
	if (ft_stsize(stack_a) > 4)
		pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_stsize(stack_a) > 3)
	{
		valopti = bigcostmin(stack_a, stack_b);
		midsortmin(stack_a, stack_b, valopti);
	}
}

void	midsortmin(t_stack **stack_a, t_stack **stack_b, int valopti)
{
	int	i;
	int	tb;
	int	ta;

	tb = ft_stsize(stack_b);
	ta = ft_stsize(stack_a);
	i = rchvalmin(stack_b, valopti);
	ltlsortmin(stack_a, stack_b, i, valopti);
}

void	ltlsortmin(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	while ((ft_intindex(stack_a, b) != 0 || ft_intindex(stack_b, a) != 0))
		ltlsortminif(stack_a, stack_b, a, b);
	pb(stack_a, stack_b);
}

void	ltlsortminif(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	int	tb;
	int	ta;

	tb = ft_stsize(stack_b);
	ta = ft_stsize(stack_a);
	if (ft_intindex(stack_b, a) <= tb / 2 && ft_intindex(stack_a, b) <= ta / 2
		&& ft_intindex(stack_b, a) != 0 && ft_intindex(stack_a, b) != 0)
		rr(stack_a, stack_b);
	else if (ft_intindex(stack_b, a) <= tb / 2 && ft_intindex(stack_b, a) != 0)
		rb(stack_b);
	else if (ft_intindex(stack_a, b) <= ta / 2 && ft_intindex(stack_a, b) != 0)
	{
		ra(stack_a);
	}
	if (ft_intindex(stack_b, a) > tb / 2 && ft_intindex(stack_a, b) > ta / 2
		&& ft_intindex(stack_b, a) != 0 && ft_intindex(stack_a, b) != 0)
		rrr(stack_a, stack_b);
	else if (ft_intindex(stack_b, a) > tb / 2)
		rrb(stack_b);
	else if (ft_intindex(stack_a, b) > ta / 2)
		rra(stack_a);
}
