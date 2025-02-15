/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:14:40 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 22:37:25 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

#include "libft/libft.h"
#include "push_swap.h"

int    bigcost(t_stack **stack_a, t_stack **stack_b)
{
    int        lowst;
    t_stack    *tmp;
    int        valowst;

    valowst = 0;
    lowst = INT_MAX;
    tmp = (*stack_b);
    while (tmp)
    {
        if (lowst > ltlcost(stack_a, stack_b, rchfv(stack_a, tmp->value),
                ft_intindex(stack_b, tmp->value)))
        {
            lowst = ltlcost(stack_a, stack_b, rchfv(stack_a, tmp->value),
                    ft_intindex(stack_b, tmp->value));
            valowst = tmp->value;
        }
        tmp = tmp->next;
    }
    return (valowst);
}

int    ltlcost(t_stack **stack_a, t_stack **stack_b, int ia, int ib)
{
    int    cost;
    int    tb;
    int    ta;

    cost = 1;
    tb = (ft_stsize(stack_b) - 1) / 2;
    ta = (ft_stsize(stack_a) - 1) / 2;
    if (ia <= ta && ib <= tb)
    {
        if (ia > ib)
            cost += ia;
        else
            cost += ib;
    }
    else if (ia <= ta)
        cost += ia;
    else if (ib <= tb)
        cost += ib;
    if (ia > ta && ib > tb)
    {
        if (ia <= ib)
            cost += (ft_stsize(stack_a) - ia);
        else
            cost += (ft_stsize(stack_b) - ib);
    }
    else if (ia > ta)
        cost += (ft_stsize(stack_a) - ia);
    else if (ib > tb)
        cost += (ft_stsize(stack_b) - ib);
    return (cost);
}