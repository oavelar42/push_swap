/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/25 19:32:39 by oavelar          ###   ########.fr       */
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
void            sort_list(t_stack *list, t_stack **sort_point, int pol);
void	        insert_end(t_stack **all, int value);
void            pa_push_to_a(t_stack **a, t_stack **b, int print, int sg);
void            ft_unallocate(t_stack **all);
void            push_other(t_stack **from, t_stack **to);
void            sort(t_stack **a, t_stack **b, int sg);
void            ft_on_off(int *i, int *sg, char **av);
void            ft_the_end(char *s);

#endif