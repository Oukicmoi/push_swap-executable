/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:31:04 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 20:58:39 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_intindex(t_stack **lst, int n)
{
	t_stack	*tmp;
	int		i;

	tmp = (*lst);
	i = 0;
	while (tmp && n != tmp->value)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_stsize(t_stack **lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*lst);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	fct_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
