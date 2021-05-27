/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:04:24 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/27 20:18:06 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    deallocate_finish(t_stack **a, t_stack **b, char *s)
{
    ft_unallocate(a);
    ft_unallocate(b);
    ft_the_end(s);
}

int     parse_input(char *line, t_stack **a, t_stack **b, int sg)
{
    if (!ft_strncmp(line, "sa", 3))
        sa_swap(*a, *b, 0, sg);
    else if (!ft_strncmp(line, "sb", 3))
        sb_swap(*a, *b, 0, sg);
    else if (!ft_strncmp(line, "ss", 3))
        ss_swap(*a, *b, 0, sg);
    else if (!ft_strncmp(line, "ra", 3))
        ra_rotate_up(a, b, 0, sg);
    else if (!ft_strncmp(line, "rb", 3))
        rb_rotate_up(a, b, 0, sg);
    else if (!ft_strncmp(line, "rr", 3))
        rr_rotate_up(a, b, 0, sg);
    else if (!ft_strncmp(line, "rra", 4))
        rra_rotate_down(a, b, 0, sg);
    else if (!ft_strncmp(line, "rrb", 4))
        rrb_rotate_down(a, b, 0, sg);
    else if (!ft_strncmp(line, "rrr", 4))
        rrr_rotate_down(a, b, 0, sg);
    else if (!ft_strncmp(line, "pb", 3))
        pb_push_to_b(a, b, 0, sg);
    else if (!ft_strncmp(line, "pa", 3))
        pa_push_to_a(a, b, 0, sg);
    else
        return (1);
    return (0);    
}

int     get_input(t_stack **a, t_stack **b, int sg)
{
    int     ret;
    char    *line;

    while (1)
    {
        ret = get_next_line(0, &line);
        if (ret == 0)
        {
            free(line);
            break ;
        }
        if (parse_input(line, a, b, sg))
        {
            free(line);
            ft_unallocate(a);
            ft_unallocate(b);
            write(2, "ERROR\n", 6);
            return (1);
        }
        if (ret == -1)
            deallocate_finish(a, b, "Next line wrong\n");
        free(line);
    }
    return (0);
}

int     main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    int     i;
    int     sg;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !ft_strncmp(av[1], "-v", 3)))
        return (0);
    ft_on_off(&i, &sg, av);
    if (check_input(ac - i, av + i))
        return (1);
    parse_number(av, &a, ac, i);
    if (check_dual(&a))
        return (1);
    if (get_input(&a, &b, sg))
        return (1);
    if (!ft_okay(a, b, ft_count(a)))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    ft_unallocate(&a);
    ft_unallocate(&b);
    return (0);
}