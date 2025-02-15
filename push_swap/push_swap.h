/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:49:29 by gtraiman          #+#    #+#             */
/*   Updated: 2024/02/11 22:08:56 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* Définition d'une Pile */
typedef struct t_stack
{
	int				value;
	struct t_stack	*next;
}					t_stack;

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				r(t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_b, t_stack **stack_a);
void				rrc(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrr(t_stack **stack_a, t_stack **stack_b);
int					ft_statoi(const char *nptr, int *error);
void				ft_stadd_back(t_stack **lst, t_stack *new);
void				ft_stclear(t_stack **lst);
t_stack				*ft_stlast(t_stack *lst);
void				printstack(char *stackName, t_stack **stack);
t_stack				*ft_stnew(int value);
int					initialize_stack(int ac, char **av, t_stack **stack_a);
void				boucle_stackinit(char **k, t_stack **stack_a, int *error);
void				checkdbl(t_stack *stack_a, int *error);
void				sort_five(t_stack *stack_a, t_stack *stack_b);
int					rchfv(t_stack **stack_a, int b);
int					costcal(t_stack *stack_a, t_stack *stack_b, int k);
void				ltlsort(t_stack **stack_a, t_stack **stack_b, int a, int b);
int					ft_stsize(t_stack **lst);
int					rchfval(t_stack **stack_a, int b);
int					ft_intindex(t_stack **lst, int n);
void				allthree(t_stack **stack_a, t_stack **stack_b);
void				midsort(t_stack **stack_a, t_stack **stack_b, int b);
void				final_sort(t_stack **stack_a);
void				emptyb(t_stack **stack_a, t_stack **stack_b);
int					findvalmin(t_stack **stack_a);
int					ltlcost(t_stack **stack_a, t_stack **stack_b, int ia,
						int ib);
char				**ft_split(char const *s, char c, int *error);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					bigcost(t_stack **stack_a, t_stack **stack_b);

int					ft_abs(int n);
int					rchimin(t_stack **stack_b, int b);
int					rchvalmin(t_stack **stack_b, int b);
int					findvalmax(t_stack **stack_b);
int					bigcostmin(t_stack **stack_a, t_stack **stack_b);
void				ltlsortmin(t_stack **stack_a, t_stack **stack_b, int a,
						int b);
void				midsortmin(t_stack **stack_a, t_stack **stack_b, int a);

void				allthree1(t_stack **stack_a, t_stack **stack_b);
void				ltlsortif(t_stack **stack_a, t_stack **stack_b, int a,
						int b);

void				stacopy(t_stack **stack_copiee, t_stack **stack_copieuse);
int					midcost(t_stack **stack_a, t_stack **stack_b);

int					ltlcostmin(t_stack **stack_a, t_stack **stack_b, int ia,
						int ib);

void				rnbr(char *str, int n);

int					ft_sort_cost_a(t_stack *lst_a, t_stack *lst_b,
						t_stack *temp);
void				sort_three(t_stack **stack);

void				fct_exit(void);

// stack_cmd_rrr;

void				rrc(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// stack_cmd_pp;

void				pa(t_stack **pile_a, t_stack **pile_b);
void				pb(t_stack **pile_a, t_stack **pile_b);

void				free_tab(char **tab);

void				boucle_stackinitab(char **k, t_stack **stack_a, int *error);
int					ltlvals(t_stack **stack_a);

void				ft_stdelone(t_stack **lst, int todel);
void				ltlsortminif(t_stack **stack_a, t_stack **stack_b, int a,
						int b);
void				final_sort_while(t_stack *tmp, int *i, int *imin,
						int *valmin);
int					ltlcostif(int ta, int tb, int ia, int ib);

#endif