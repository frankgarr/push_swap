/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:05:27 by frankgar          #+#    #+#             */
/*   Updated: 2024/02/01 11:52:24 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*bottom_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	rotate(t_stack *stack, char flag)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return (-1);
	tmp = bottom_node(stack);
	tmp->next = stack->top;
	stack->top = stack->top->next;
	tmp->next->next = NULL;
	if (flag == 'a')
		ft_printf("ra\n");
	else if (flag == 'b')
		ft_printf("rb\n");
	return (0);
}

int	reverse_rotate(t_stack *stack, char flag)
{
	t_node	*tmp;
	t_node	*bottom;

	if (!stack || stack->size < 2)
		return (-1);
	bottom = bottom_node(stack);
	tmp = stack->top;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	bottom->next = stack->top;
	stack->top = bottom;
	if (flag == 'a')
		ft_printf("rra\n");
	else if (flag == 'b')
		ft_printf("rrb\n");
	return (0);
}

int	double_rotate(t_stack *stacka, t_stack *stackb)
{
	if (!stacka || rotate(stacka, 0) || !stackb || rotate(stackb, 0))
		return (-1);
	ft_printf("rr\n");
	return (0);
}

int	double_reverse_rotate(t_stack *stacka, t_stack *stackb)
{
	if (!stacka || reverse_rotate(stacka, 0) \
		|| !stackb || reverse_rotate(stackb, 0))
		return (-1);
	ft_printf("rrr\n");
	return (0);
}
