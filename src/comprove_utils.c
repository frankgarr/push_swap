/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprove_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:50:29 by frankgar          #+#    #+#             */
/*   Updated: 2024/01/31 10:16:01 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack->top;
	i = 0;
	while (i < stack->size && tmp)
	{
		if (tmp->next && !(tmp->index < tmp->next->index))
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
