/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:24:19 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 21:41:19 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*ft_stlast(t_stack *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	printstack(char *stackname, t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	ft_putstr_fd(stackname, 1);
	write(1, " : ", 3);
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

t_stack	*ft_stnew(int value)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

void	checkdbl(t_stack *stack_a, int *error)
{
	t_stack	*temp;

	temp = NULL;
	temp = (ft_stlast(stack_a));
	while (stack_a != temp)
	{
		if (temp->value == stack_a->value)
		{
			*error = 1;
			return ;
		}
		stack_a = stack_a->next;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
