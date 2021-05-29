/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:03:55 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/29 12:08:31 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_top_three_a(t_stack **a, t_stack **b, int sg)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x < y && y < z && x < z)
	{
		(*a)->pol = 0;
		(*a)->next->pol = 0;
		(*a)->next->next->pol = 0;
	}
	else if (x < y && y > z && x < z)
		sort_a_one_three_two_a(a, b, sg);
	else if (x > y && y < z && x < z)
		sort_a_two_one_three_a(a, b, sg);
	else if (x < y && y > z && x > z)
		sort_a_two_three_one(a, b, sg);
	else if (x > y && y < z && x > z)
		sort_a_three_one_two(a, b, sg);
	else if (x > y && y > z && x > z)
		sort_a_three_two_one(a, b, sg);
}

void	ft_sort_top_a(t_stack **a, t_stack **b, int sg)
{
	if (count_not_sort(*a) == 0)
		ft_the_end("Something went wrong\n");
	else if (count_not_sort(*a) == 1)
		(*a)->pol = 0;
	else if (count_not_sort(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa_swap(*a, *b, 1, sg);
		(*a)->pol = 0;
		(*a)->next->pol = 0;
	}
	else if (count_not_sort((*a)) == 3)
		sort_top_three_a(a, b, sg);
}