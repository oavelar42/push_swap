/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/19 19:25:33 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_unallocate(t_stack **a, t_stack **b, int sg)
{
    sort(a, b, sg);
    ft_unallocate(a);
    ft_unallocate(b);
    return (0);
}

void    ft_unallocate(t_stack **all)
{
    t_stack *curr;
    t_stack *aux;

    curr = *all;
    while (curr != NULL)
    {
        aux = curr;
        curr = curr->next;
        free(aux);
    }
    *all = NULL;
}

int     ft_okay(t_stack *a, t_stack *b, int init_len)
{
    int prev;

    if (ft_count(a) != init_len)
        return (1);
    else if (ft_count(b) != 0)
        return (1);
    else
    {
        prev = a->value;
        a = a->next;
        while (a != NULL)
        {
            if (a->value < prev)
                return (1);
            prev = a->value;
            a = a->next
        }
    }
    return (0);
}

void    ft_the_end(char *s)
{
    ft_putstr_fd(s, 2);
    exit(1);
}