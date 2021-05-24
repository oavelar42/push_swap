/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/24 15:54:06 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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