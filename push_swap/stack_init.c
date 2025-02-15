/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:51:40 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 21:41:53 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	initialize_stack(int ac, char **av, t_stack **stack_c)
{
	int		error;
	char	**j;

	error = 0;
	if (ac < 2 || av[1][0] == 0)
		fct_exit();
	if (ac == 2)
	{
		j = ft_split(av[1], ' ', &error);
		boucle_stackinitab(j, stack_c, &error);
		if (error == 1)
			return (2);
		if (error == 3)
			return (1);
	}
	else
	{
		boucle_stackinit(av, stack_c, &error);
		if (error == 1)
			return (2);
		if (error == 3)
			return (1);
	}
	printstack("stack_a", stack_c);
	return (0);
}

void	boucle_stackinit(char **k, t_stack **stack_a, int *error)
{
	int	i;

	i = 1;
	while (k[i])
	{
		ft_stadd_back(stack_a, ft_stnew(ft_statoi(k[i], error)));
		checkdbl(*stack_a, error);
		if (*error == 1)
		{
			ft_stclear(stack_a);
			return ;
		}
		i++;
	}
	if (ltlvals(stack_a) == 1)
	{
		*error = 3;
		return ;
	}
}

void	boucle_stackinitab(char **k, t_stack **stack_a, int *error)
{
	int	i;

	i = 0;
	while (k[i])
	{
		ft_stadd_back(stack_a, ft_stnew(ft_statoi(k[i], error)));
		checkdbl(*stack_a, error);
		if (*error == 1)
		{
			free_tab(k);
			ft_stclear(stack_a);
			return ;
		}
		i++;
	}
	free_tab(k);
	if (ltlvals(stack_a) == 1)
	{
		*error = 3;
		return ;
	}
}

int	ltlvals(t_stack **stack_a)
{
	int	tmp;

	tmp = 0;
	if (ft_stsize(stack_a) < 4)
	{
		if (ft_stsize(stack_a) == 2)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}
		if (ft_stsize(stack_a) == 3)
			sort_three(stack_a);
		return (1);
	}
	return (0);
}
