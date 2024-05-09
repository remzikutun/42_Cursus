/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:24:00 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/05 11:35:56 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_container
{
	int					value;
	long long			index;
	struct s_container	*next;
}						t_container;

typedef struct s_stack
{
	t_container	*container;
	int			size;
	int			r_count;
}				t_stack;

typedef struct s_three_element
{
	int			first;
	int			second;
	int			third;
}				t_three_element;

int			is_integer_max_min(char **av);
int			is_shorting(char **av);
int			is_repeat_digit(int ac, char **av);
int			is_check(int ac, char **av, int flag);

int			is_container_sorted(t_stack *stack, int max_index, int min_index);
void		sa_sort_three(t_stack **stack_a, t_stack **stack_b);
void		sa_more_than_3_three_sort(t_stack **stack_a, t_stack **stack_b,
				t_three_element a);
void		sa_sb_sort(t_stack **stack_a, t_stack **stack_b,
				t_three_element a);

int			is_container_reverse_sorted(t_stack *stack,
				int max_index, int min_index);
void		sb_reverse_sort_three(t_stack **stack_a, t_stack **stack_b,
				t_three_element b);
void		sb_a_push_sort_three(t_stack **stack_a, t_stack **stack_b,
				t_three_element b);

void		sa_push_b_opretion(t_stack **stack_a, t_stack **stack_b,
				int max_index, int min_index);
void		sb_push_a_opretion(t_stack **stack_a, t_stack **stack_b,
				int max_index, int min_index);

int			stack_operations(int ac, char **av, t_stack **stack_a);
void		container_index(t_stack **stack_a);

void		free_stack(t_stack **stack_a, t_stack **stack_b);
int			ft_list_container_add_back(t_container **lst, t_container *new);
int			ft_list_size(t_container *lst);

void		r(t_stack **stack, char flag);
void		s(t_stack **stack, char flag);
void		p(t_stack **stack_a, t_stack **stack_b, char flag);
void		rr(t_stack **stack, int flag);

void		all_r(t_stack **stack_a, t_stack **stack_b, int flag);
void		all_s(t_stack **stack_a, t_stack **stack_b, int flag);
void		all_rr(t_stack **stack_a, t_stack **stack_b, int flag);
void		ss_push(t_stack **first_stack, t_stack **second_stack, char flag);

char		*ft_copy_to_stash(char *stash, char *buf, t_stack **stack_a,
				t_stack **stack_b);
int			ft_have_nl(char *s);
char		*ft_extract_line(char *stash);
char		*ft_recreate_stash(char *stash, t_stack **stack_a,
				t_stack **stack_b);
void		*ft_free_stash(char **stash, int create_line, t_stack **stack_a,
				t_stack **stack_b);
int			ft_strcmp(const char *s1, const char *s2);
void		chk_p(t_stack **stack_a, t_stack **stack_b, char flag);

#endif
