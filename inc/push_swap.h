/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:25:51 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/16 20:05:27 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int				index;
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int	parsing(int argc, char **argv);
int	is_ordered(t_stack *stack);
int	push(t_stack *stack_dst, t_stack *stack_src, char flag);
int	rotate(t_stack *stack, char flag);
int	reverse_rotate(t_stack *stack, char flag);
int	double_rotate(t_stack *stacka, t_stack *stackb);
int	double_reverse_rotate(t_stack *stacka, t_stack *stackb);
int	swap(t_stack *stack, char flag);
int	double_swap(t_stack *stack1, t_stack *stack2);
int	push_node(t_stack *stack, int num, int index);
int	size_3(t_stack *stack);
int	print_stack(t_stack *stack, char name);
int	best_move(t_stack *stack, int num, char flag);
int	ft_find_index(t_stack *stack, char flag);
int	best_move_range(t_stack *stack1, int min, int max, int *stt);
int	move_node(t_stack *stack, int num, char flag);
int	big_size(t_stack *stack1, t_stack *stack2);
int	rondabout(t_stack *stack1, t_stack *stack2);
int	wipe_nodes(t_stack *a, t_stack*b);
int	push_swap(int argc, char **argv);

#endif
