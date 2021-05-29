/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_a_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:38:18 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/29 12:09:12 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_one_three_two_a(t_stack **a, t_stack **b, int sg)
{
	(*a)->pol = 0;
	(*a)->next->pol = 0;
	(*a)->next->next->pol = 0;
	if (ft_count(*a) == 3)
	{
		sa_swap(*a, *b, 1, sg);
		ra_rotate_up(a, b, 1, sg);
	}
	else
	{
		ra_rotate_up(a, b, 1, sg);
		sa_swap(*a, *b, 1, sg);
		rra_rotate_down(a, b, 1, sg);
	}
}

void	sort_a_two_one_three_a(t_stack **a, t_stack **b, int sg)
{
	(*a)->pol = 0;
	(*a)->next->pol = 0;
	(*a)->next->next->pol = 0;
	sa_swap(*a, *b, 1, sg);
}

void	sort_a_two_three_one(t_stack **a, t_stack **b, int sg)
{
	(*a)->pol = 0;
	(*a)->next->pol = 0;
	(*a)->next->next->pol = 0;
	if (ft_count(*a) == 3)
		rra_rotate_down(a, b, 1, sg);
	else
	{
		ra_rotate_up(a, b, 1, sg);
		sa_swap(*a, *b, 1, sg);
		rra_rotate_down(a, b, 1, sg);
		sa_swap(*a, *b, 1, sg);
	}
}

void	sort_a_three_one_two(t_stack **a, t_stack **b, int sg)
{
	(*a)->pol = 0;
	(*a)->next->pol = 0;
	(*a)->next->next->pol = 0;
	if (ft_count(*a) == 3)
		ra_rotate_up(a, b, 1, sg);
	else
	{
		sa_swap(*a, *b, 1, sg);
		ra_rotate_up(a, b, 1, sg);
		sa_swap(*a, *b, 1, sg);
		rra_rotate_down(a, b, 1, sg);
	}
}

void	sort_a_three_two_one(t_stack **a, t_stack **b, int sg)
{
	(*a)->pol = 0;
	(*a)->next->pol = 0;
	(*a)->next->next->pol = 0;
	if (ft_count(*a) == 3)
	{
		ra_rotate_up(a, b, 1, sg);
		sa_swap(*a, *b, 1, sg);
	}
	else
	{
		sa_swap(*a, *b, 1, sg);
		ra_rotate_up(a, b, 1, sg);
		sa_swap(*a, *b, 1, sg);
		rra_rotate_down(a, b, 1, sg);
		sa_swap(*a, *b, 1, sg);
	}
}