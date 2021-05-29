/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:35:10 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/29 12:01:57 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_swap(t_stack *a, t_stack *b, int print, int sg)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
	if (sg)
		print_stacks(a, b);
}

void	sb_swap(t_stack *a, t_stack *b, int print, int sg)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
	if (sg)
		print_stacks(a, b);
}

void	sa_swap(t_stack *a, t_stack *b, int print, int sg)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
	if (sg)
		print_stacks(a, b);
}

void	pa_push_to_a(t_stack **a, t_stack **b, int print, int sg)
{
	if (*b != NULL)
		(*b)->pol *= -1;
	push_other(b, a);
	if (print)
		write(1, "pa\n", 3);
	if (sg)
		print_stacks(*a, *b);
}

void	pb_push_to_b(t_stack **a, t_stack **b, int print, int sg)
{
	if (*a != NULL)
		(*a)->pol *= -1;
	push_other(a, b);
	if (print)
		write(1, "pb\n", 3);
	if (sg)
		print_stacks(*a, *b);
}