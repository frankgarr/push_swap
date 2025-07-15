/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:58:11 by frankgar          #+#    #+#             */
/*   Updated: 2024/04/27 13:13:49 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_node(t_stack *stack, int num, char flag)
{
	t_node	*tmp;
	int		i;

	i = ((num < 0) * 1) + ((num > 0) * -1);
	tmp = stack->top;
	if (num == 0)
		return (-1);
	while (num != 0)
	{
		if (num < 0)
			reverse_rotate(stack, flag);
		else
			rotate(stack, flag);
		num += i;
	}
	return (0);
}

int	best_move_range(t_stack *stack1, int min, int max, int *stt)
{
	t_node	*tmp;
	int		size_fst;
	int		size_lst;
	int		i;

	i = 0;
	size_fst = -1;
	size_lst = -1;
	tmp = stack1->top;
	while (tmp)
	{
		if ((tmp->index >= min && tmp->index <= max) && size_fst == -1)
			size_fst = i;
		if (tmp->index >= min && tmp->index <= max && size_fst >= 0)
			size_lst = i;
		i++;
		tmp = tmp->next;
	}
	if (size_fst == -1 && size_lst == -1)
		*stt = -1;
	else if (size_fst <= (stack1->size - size_lst))
		return (size_fst);
	else
		return (-(stack1->size - size_lst));
	return (0);
}

int	best_move(t_stack *stack1, int num, char flag)
{
	t_node	*tmp;
	int		i;
	int		direction;

	i = 0;
	tmp = stack1->top;
	while (tmp && tmp->index != num)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp || tmp->index != num)
		return (-1);
	direction = (i <= (stack1->size / 2));
	if (i > stack1->size / 2)
		i = stack1->size - i;
	while (i > 0)
	{
		if (direction == 1)
			rotate(stack1, flag);
		else
			reverse_rotate(stack1, flag);
		i--;
	}
	return (0);
}

int	ft_find_index(t_stack *stack, char flag)
{
	t_node	*tmp;
	int		max;
	int		min;

	tmp = stack->top;
	max = tmp->index;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	if (flag == 'M')
		return (max);
	if (flag == 'm')
		return (min);
	return (-1);
}

int	size_3(t_stack *stack)
{
	if (is_ordered(stack))
	{
		printf("Stack: %d -> %d -> %d\n", stack->top->num, stack->top->next->num, stack->top->next->next->num);
		if (!stack->top)
			return (-1);
		if (stack->top->num < stack->top->next->num)
			reverse_rotate(stack, 'a');
		else if (stack->top->num > stack->top->next->next->num)
			rotate(stack, 'a');
		if (is_ordered(stack))
			swap(stack, 'a');
		return (0);
	}
	return (1);
}
