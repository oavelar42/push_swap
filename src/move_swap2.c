/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:34:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/29 12:04:37 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_rotate_down(t_stack **a, t_stack **b, int print, int sg)
{
	rotate_down(b);
	if (print)
		write(1, "rrb\n", 4);
	if (sg)
		print_stacks(*a, *b);
}

void	rra_rotate_down(t_stack **a, t_stack **b, int print, int sg)
{
	rotate_down(a);
	if (print)
		write(1, "rra\n", 4);
	if (sg)
		print_stacks(*a, *b);
}

void	rr_rotate_up(t_stack **a, t_stack **b, int print, int sg)
{
	rotate_up(a);
	rotate_up(b);
	if (print)
		write(1, "rr\n", 3);
	if (sg)
		print_stacks(*a, *b);
}

void	rb_rotate_up(t_stack **a, t_stack **b, int print, int sg)
{
	rotate_up(b);
	if (print)
		write(1, "rb\n", 3);
	if (sg)
		print_stacks(*a, *b);
}

void	ra_rotate_up(t_stack **a, t_stack **b, int print, int sg)
{
	rotate_up(a);
	if (print)
		write(1, "ra\n", 3);
	if (sg)
		print_stacks(*a, *b);
}