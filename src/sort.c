/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/24 17:03:46 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_b_first_time(t_stack **a, t_stack **b, int sg)
{
    int med;
    int pol;

    if (count_not_sort(*a) <= 3)
    {
        ft_sort_top_a(a, b, sg);
        return ;
    }
    pol = (*a)->pol;
    med = find_med_part(*a);
    if (ft_count(*a) < 6)
        med -= 1;
    while ((*a)->pol == pol)
        sort_b_push(a, b, med, sg);
    return (sort_b_first_time(a, b, sg));
}

void    sort(t_stack **a, t_stack **b, int sg)
{
    if (ft_count(*a) == 0)
        return ;
    if (ft_count_pol(*a, (*a)->pol) == ft_count(*a))
        sort_b_first_time(a, b, sg);
    else
        sort_b_with_sort(a, b, sg);
    push_half_a(a, b, sg);
    if (!ft_okay(*a, *b, ft_count(*a)))
        return ;
    return (sort(a, b, sg));
}