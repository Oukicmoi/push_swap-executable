/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fst_n_lst_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:32:50 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 21:40:53 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	while (!((((*stack_a)->value) < (((*stack_a)->next)->value))
			&& (((*stack_a)->next->value) < ((*stack_a)->next->next->value))))
	{
		if ((((*stack_a)->value) > (((*stack_a)->next)->value))
			&& ((((*stack_a)->value) > ((((*stack_a)->next)->next)->value))))
			ra(&(*stack_a));
		else if (((*stack_a)->value) > (((*stack_a)->next)->value))
		{
			sa(stack_a);
		}
		else
		{
			rra(stack_a);
		}
	}
}

void	final_sort(t_stack **stack_a)
{
	int		i;
	int		imin;
	int		valmin;
	t_stack	*tmp;

	tmp = (*stack_a);
	valmin = INT_MAX;
	i = 0;
	imin = 0;
	final_sort_while(tmp, &i, &imin, &valmin);
	i = 0;
	while (imin != 0 && imin <= ft_stsize(stack_a) / 2)
	{
		ra(stack_a);
		imin--;
	}
	while (imin != ft_stsize(stack_a) - 1 && imin > ft_stsize(stack_a) / 2)
	{
		rra(stack_a);
		imin++;
		i++;
	}
	if (imin == ft_stsize(stack_a) - 1)
		rra(stack_a);
	printstack("stack a", stack_a);
}

void	final_sort_while(t_stack *tmp, int *i, int *imin, int *valmin)
{
	while (tmp)
	{
		if (((tmp))->value < *valmin)
		{
			*valmin = (tmp)->value;
			*imin = *i;
		}
		*i = *i + 1;
		(tmp) = (tmp)->next;
	}
}
