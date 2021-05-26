/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:34:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/26 11:52:58 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra_rotate_down(t_stack **a, t_stack **b, int print, int sg)
{
    rotate_down(a);
    if (print)
        write(1, "rra\n", 4);
    if (sg)
        print_stacks(*a, *b);
}

void    ra_rotate_up(t_stack **a, t_stack **b, int print, int sg)
{
    rotate_up(a);
    if (print)
        write(1, "ra\n", 3);
    if (sg)
        print_stacks(*a, *b);
}