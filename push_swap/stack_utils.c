/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:25:14 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 21:42:29 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_statoi(const char *nptr, int *error)
{
	int			i;
	int			s;
	long int	num;

	i = 0;
	s = 1;
	num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+') && nptr[i + 1])
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		if ((s == 1 && num > INT_MAX) || (s == -1 && num * s < INT_MIN))
			*error = 1;
		i++;
	}
	if (nptr[i])
		*error = 1;
	return (num * s);
}

void	ft_stadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_stclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	lst = NULL;
}

void	rnbr(char *str, int n)
{
	ft_putstr_fd(str, 1);
	ft_putnbr_fd(n, 1);
}

void	ft_stdelone(t_stack **lst, int todel)
{
	t_stack	*previous;
	t_stack	*current;

	if (!lst)
		return ;
	current = *lst;
	previous = NULL;
	while (current)
	{
		if (current->value == todel)
		{
			if (previous)
				previous->next = current->next;
			else
				*lst = current->next;
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
