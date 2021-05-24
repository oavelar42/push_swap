/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:35:10 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/24 23:04:09 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa_push_to_a(t_stack **a, t_stack **b, int print, int sg)
{
    if (*b != NULL)
        (*b)->pol *= -1;
    push_other(b, a);
    if (print)
        write(1, "pa\n", 3);
    if (sg)
        print_stacks(*a, *b);
}