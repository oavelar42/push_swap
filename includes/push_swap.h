/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/26 15:34:04 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
    int             value;
    int             pol;
    struct s_stack *next;
}               t_stack;

int             ft_okay(t_stack *a, t_stack *b, int init_len);
int             find_med_part(t_stack *list);
int             check_dual(t_stack **a);
int		        check_list_dual(t_stack *sort_list);
int             check_input(int ac, char **s);
int	        	ft_count(t_stack *list);
int             count_not_sort(t_stack *list);
int             ft_count_pol(t_stack *list, int pol);
void	        insert_init(t_stack **all, int value);
void	        insert_sort(t_stack **all, int value);
void            parse_number(char **av, t_stack **a, int ac, int i);
void            print_stacks(t_stack *a, t_stack *b);
void            ra_rotate_up(t_stack **a, t_stack **b, int print, int sg);
void            rotate_down(t_stack **list);
void            rotate_up(t_stack **list);
void            rra_rotate_down(t_stack **a, t_stack **b, int print, int sg);
void            sa_swap(t_stack *a, t_stack *b, int print, int sg);
void            sort_a_one_three_two_a(t_stack **a, t_stack **b, int sg);
void            sort_a_three_one_two(t_stack **a, t_stack **b, int sg);
void            sort_a_three_two_one(t_stack **a, t_stack **b, int sg);
void            sort_a_two_one_three_a(t_stack **a, t_stack **b, int sg);
void            sort_a_two_three_one(t_stack **a, t_stack **b, int sg);
void            sort_list(t_stack *list, t_stack **sort_point, int pol);
void	        insert_end(t_stack **all, int value);
void            pb_push_to_b(t_stack **a, t_stack **b, int print, int sg);
void            pa_push_to_a(t_stack **a, t_stack **b, int print, int sg);
void            ft_unallocate(t_stack **all);
void            push_other(t_stack **from, t_stack **to);
void            sort(t_stack **a, t_stack **b, int sg);
void            sort_top_a(t_stack **a, t_stack **b, int sg);
void            ft_on_off(int *i, int *sg, char **av);
void            swap(t_stack *list);
void            ft_the_end(char *s);

#endif