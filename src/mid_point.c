/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/24 22:55:20 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_list(t_stack *list, t_stack **sort_point, int pol)
{
    *sort_point = NULL;
    insert_sort(sort_point, list->value);
    while (list->next != NULL && list->pol == pol)
    {
        list = list->next;
        if (list->pol == pol)
            insert_sort(sort_point, list->value);
        else
            break ;
    }
}

int     count_not_sort(t_stack *list)
{
    if (list == NULL)
        return (0);
    while (list != NULL && list->pol == 0)
        list = list->next;
    if (list == NULL)
        return (0);
    return (1 + count_not_sort(list->next));
}