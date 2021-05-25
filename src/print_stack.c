/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:05:57 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/25 19:06:54 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_one(t_stack *s)
{
    ft_putnbr_fd(s->value, 2);
    if (s->value > 9999999 || s->value < -999999)
        write(2, "\t", 1);
    else
        write(2, "\t\t", 2);
    ft_putnbr_fd(s->pol, 2);
}

void    print_stacks(t_stack *a, t_stack *b)
{
    write(2, "+-------------+-------------+\n", 30);
    write(2, "|      a      |      b      |\n", 30);
    write(2, "+-------------+-------------+\n", 30);
    while (a || b)
    {
        if (a)
        {
            print_one(a);
            write(2, "\t", 1);
            a = a->next;
        }
        else
            write(2, "-\t\t\t", 4);
        if (b)
        {
            print_one(b);
            b = b->next;
        }
        write(2, "\n", 1);
    }
}