/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:35:32 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/06 16:29:33 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	findvalmin(t_stack **stack_a)
{
	t_stack	*tmp;
	int		min;

	min = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	findvalmax(t_stack **stack_b)
{
	t_stack	*tmp;
	int		max;

	max = INT_MIN;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
