/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:14:19 by frankgar          #+#    #+#             */
/*   Updated: 2024/02/01 11:58:25 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_node(t_stack *stack, int num, int index)
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

int	pop_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	stack->size--;
	stack->top = stack->top->next;
	free(tmp);
	return (0);
}

int	push(t_stack *stack_dst, t_stack *stack_src, char flag)
{
	if (!stack_src || stack_src->size == 0 || !stack_src->top)
		return (-1);
	push_node(stack_dst, stack_src->top->num, stack_src->top->index);
	pop_node(stack_src);
	if (flag == 'a')
		ft_printf("pa\n");
	else if (flag == 'b')
		ft_printf("pb\n");
	return (0);
}
