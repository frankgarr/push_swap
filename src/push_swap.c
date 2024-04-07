/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:40:47 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/16 20:04:56 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rondabout(t_stack *stack1, t_stack *stack2)
{
	int	min;
	int	stt;

	min = ft_find_index(stack1, 'm');
	if (stack1->size == 2)
		swap(stack1, 'a');
	else if (stack1->size == 3 && is_ordered(stack1))
		size_3(stack1);
	else if (stack1->size == 4)
	{
		if (stack1->top->index != min)
			best_move(stack1, min, 'a');
		stt = push(stack2, stack1, 'b') + size_3(stack1)
			+ push(stack1, stack2, 'a');
	}
	else if (stack1->size == 5)
	{
		if (stack1->top->index != min)
			best_move(stack1, min, 'a');
		stt = push(stack2, stack1, 'b') + rondabout(stack1, stack2)
			+ push(stack1, stack2, 'a');
	}
	else
		big_size(stack1, stack2);
	return (0);
}

int	assign_order(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = stack->top;
	while (tmp1)
	{
		tmp2 = stack->top;
		while (tmp2)
		{
			if (tmp1->num > tmp2->num)
				tmp1->index++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	stack_push(t_stack *stack, int num, int index)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		exit((ft_fd_printf(2, "Error\n") * 0) + 1);
	node->num = num;
	node->index = index;
	if (stack->size != 0)
		node->next = stack->top;
	stack->top = node;
	stack->size++;
	return (0);
}

int	init_stack(t_stack *stack, int argc, char **argv)
{
	stack->top = NULL;
	stack->size = 0;
	while (stack->size < argc)
		push_node(stack, ft_atoi(argv[(argc - stack->size)]), 1);
	assign_order(stack);
	if (is_ordered(stack) == 0)
		exit(0);
	return (0);
}

int	push_swap(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	b.top = NULL;
	b.size = 0;
	parsing(argc, argv);
	init_stack(&a, argc - 1, argv);
	rondabout(&a, &b);
	wipe_nodes(&a, &b);
	return (0);
}
