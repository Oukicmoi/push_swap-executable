/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:59:00 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 21:42:18 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		state;

	state = 0;
	stack_a = NULL;
	stack_b = NULL;
	state = initialize_stack(ac, av, &stack_a);
	if (state == 1)
	{
		printstack("stack a", &stack_a);
		ft_stclear(&stack_a);
		return (0);
	}
	if (state == 2)
		return (write(2, "Error\n", 6));
	allthree1(&stack_a, &stack_b);
	sort_three(&stack_a);
	emptyb(&stack_a, &stack_b);
	final_sort(&stack_a);
	printstack("stack a", &stack_a);
	ft_stclear(&stack_a);
}
