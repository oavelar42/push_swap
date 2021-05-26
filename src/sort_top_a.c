/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:03:55 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/26 12:13:10 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_top_a(t_stack **a, t_stack **b, int sg)
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