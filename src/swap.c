/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:47:43 by frankgar          #+#    #+#             */
/*   Updated: 2024/01/25 12:37:46 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack, char flag)
{
	t_node	*tmp1;

	if (!stack && stack->size < 2)
		return (-1);
	tmp1 = stack->top;
	stack->top = tmp1->next;
	tmp1->next = stack->top->next;
	stack->top->next = tmp1;
	if (flag == 'a')
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");
	return (0);
}

int	double_swap(t_stack *stack1, t_stack *stack2)
{
	if (swap(stack1, 0) || swap(stack2, 0))
		return (-1);
	ft_printf("ss\n");
	return (0);
}
