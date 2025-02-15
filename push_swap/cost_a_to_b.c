/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:44:37 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/06 19:14:49 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	ft_near_start_a(t_stack *lst_b, int n, int t)
{
	int	cost;

	cost = 0;
	if (t <= (ft_stsize(&lst_b) - 1) - t)
	{
		while (n && t)
		{
			cost += 1;
			n--;
			t--;
		}
		cost += n + t;
	}
	else
		cost += n + ft_stsize(&lst_b) - t;
	return (cost);
}

static int	ft_near_end_a(t_stack *lst_a, t_stack *lst_b, int n, int t)
{
	int	cost;

	cost = 0;
	if (t <= (ft_stsize(&lst_b) - 1) - t)
		cost += t + ft_stsize(&lst_a) - n;
	else
	{
		while (n < ft_stsize(&lst_a) && t < ft_stsize(&lst_b))
		{
			cost += 1;
			n++;
			t++;
		}
		cost += ft_stsize(&lst_a) - n + ft_stsize(&lst_b) - t;
	}
	return (cost);
}

int	ft_sort_cost_a(t_stack *lst_a, t_stack *lst_b, t_stack *temp)
{
	int	cost;
	int	n;
	int	t;

	cost = 1;
	n = ft_intindex(&lst_a, temp->value);
	t = ft_intindex(&lst_b, rchvalmin(&lst_b, temp->value));
	if (n <= (ft_stsize(&lst_a) - 1) - n)
		cost += ft_near_start_a(lst_b, n, t);
	else
		cost += ft_near_end_a(lst_a, lst_b, n, t);
	return (cost);
}

int	bigcostmin(t_stack **stack_a, t_stack **stack_b)
{
	int		lowst;
	t_stack	*tmp;
	int		valowst;

	valowst = 0;
	lowst = INT_MAX;
	tmp = (*stack_a);
	while (tmp)
	{
		if (lowst > ft_sort_cost_a(*stack_a, *stack_b, tmp))
		{
			lowst = ft_sort_cost_a(*stack_a, *stack_b, tmp);
			valowst = tmp->value;
		}
		tmp = tmp->next;
	}
	return (valowst);
}
