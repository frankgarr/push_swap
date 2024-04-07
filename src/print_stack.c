/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:24:02 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/16 20:26:27 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	print_stack(t_stack *stack, char name)
{
	t_node	*tmp;
	int		flag;

	flag = 0;
	tmp = stack->top;
	ft_printf("-------------------------\n");
	ft_printf("Stack: %c Status size: %d\n", name, stack->size);
	ft_printf("-------------------------\n");
	ft_printf("Numbers | Index \n");
	ft_printf("--------|-------\n");
	while (tmp && flag == 0)
	{
		ft_printf("      %i | %i\n", tmp->num, tmp->index);
		if (!tmp || !tmp->next)
			flag++;
		else
			tmp = tmp->next;
	}
	ft_printf("-------------------------\n");
	return (0);
}
