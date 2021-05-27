/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/27 21:58:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_half_a(t_stack **a, t_stack **b, int sg)
{
    int pol;

    if (ft_count(*b) == 0)
        return ;
    pol = (*b)->pol;
    pa_push_to_a(a, b, 1, sg);
    if (ft_count(*b) == 0)
        return ;
    while (((*b)->next != NULL) && (*b)->pol == pol)
        pa_push_to_a(a, b, 1, sg);
    if (ft_count(*b) == 1 && (*b)->pol == pol)
        pa_push_to_a(a, b, 1, sg);
}

int     sort_b_push(t_stack **a, t_stack **b, int med, int sg)
{
    if ((*a)->value <= med)
    {
        pb_push_to_b(a, b, 1, sg);
        return (0);
    }
    else
    {
        (*a)->pol *= -1;
        ra_rotate_up(a, b, 1, sg);
        return (1);
    }
}

void    sort_b_with_sort(t_stack **a, t_stack **b, int sg)
{
    int med;
    int pol;
    int rot;

    if (count_not_sort(*a) <= 3)
    {
        ft_sort_top_a(a, b, sg);
        return ;
    }
    pol = (*a)->pol;
    med = find_med_part(*a);
    rot = 0;
    while ((*a)->pol == pol)
        rot += sort_b_push(a, b, med, sg);
    while (rot)
    {
        rra_rotate_down(a, b, 1, sg);
        rot--;
    }
    return (sort_b_with_sort(a, b, sg));
}

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