/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/26 11:57:22 by oavelar          ###   ########.fr       */
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

void    rotate_up(t_stack **list)
{
    t_stack *curr;
    t_stack *move_down;

    if (*list == NULL || ft_count(*list) < 2)
        return ;
    move_down = *list;
    curr = *list;
    while (curr->next != NULL)
        curr = curr->next;
    *list = move_down->next;
    curr->next = move_down;
    move_down->next = NULL;
}

void    rotate_down(t_stack **list)
{
    t_stack *curr;

    if (*list == NULL || ft_count(*list) < 2)
        return ;
    curr = *list;
    while (curr->next->next != NULL)
        curr = curr->next;
    curr->next->next = *list;
    *list = curr->next;
    curr->next = NULL;
}