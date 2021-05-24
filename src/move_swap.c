/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/24 22:33:23 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_other(t_stack **from, t_stack **to)
{
    t_stack *move;

    if (*from == NULL)
        return ;
    move = *from;
    *from = (*from)->next;
    move->next = *to;
    *to = move;
}