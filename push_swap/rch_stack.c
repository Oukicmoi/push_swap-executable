/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rch_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:00:41 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 21:11:55 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	rchimin(t_stack **stack_b, int b)
{
	int		i;
	int		pluspr;
	int		ipluspr;
	t_stack	*tmp;

	if (b < findvalmin(stack_b) || b > findvalmax(stack_b))
		return (ft_intindex(stack_b, (findvalmax(stack_b))));
	ipluspr = 0;
	pluspr = INT_MIN;
	i = 0;
	tmp = (*stack_b);
	while (tmp)
	{
		if (tmp->value == b - 1)
			return (i);
		if (ft_abs(tmp->value - b) <= pluspr && (tmp->value) - b <= 0)
		{
			ipluspr = i;
			pluspr = ft_abs((tmp->value) - b);
		}
		i++;
		tmp = tmp->next;
	}
	return (ipluspr);
}

int	rchvalmin(t_stack **stack_b, int b)
{
	int		i;
	int		pluspr;
	int		ipluspr;
	int		val;
	t_stack	*tmp;

	if (b < findvalmin(stack_b) || b > findvalmax(stack_b))
		return (findvalmax(stack_b));
	val = findvalmax(stack_b);
	ipluspr = 0;
	pluspr = INT_MAX;
	i = 0;
	tmp = (*stack_b);
	while (tmp)
	{
		if (ft_abs(tmp->value - b) <= pluspr && (tmp->value) - b <= 0)
		{
			ipluspr = i;
			pluspr = ft_abs((tmp->value) - b);
			val = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (val);
}

int	rchfval(t_stack **stack_a, int b)
{
	int		i;
	int		pluspr;
	int		ipluspr;
	int		val;
	t_stack	*tmp;

	val = findvalmin(stack_a);
	ipluspr = 0;
	pluspr = INT_MAX;
	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->value == b + 1)
			return (tmp->value);
		if (tmp->value - b <= pluspr && (tmp->value) - b >= 0)
		{
			ipluspr = i;
			pluspr = (tmp->value) - b;
			val = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (val);
}

int	rchfv(t_stack **stack_a, int b)
{
	int		i;
	int		pluspr;
	int		ipluspr;
	t_stack	*tmp;

	ipluspr = 0;
	pluspr = INT_MAX;
	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->value == b + 1)
			return (i);
		if (tmp->value - b <= pluspr && (tmp->value) - b >= 0)
		{
			ipluspr = i;
			pluspr = (tmp->value) - b;
		}
		i++;
		tmp = tmp->next;
	}
	return (ipluspr);
}
