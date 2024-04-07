/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:20:08 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/16 20:42:29 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wipe_nodes(t_stack *a, t_stack*b)
{
	t_node	*tmp;

	if (b->top)
	{
		tmp = b->top->next;
		while (b->top)
		{
			free(b->top);
			b->top = tmp;
			if (tmp)
				tmp = tmp->next;
		}
	}
	if (a->top)
	{
		tmp = a->top->next;
		while (a->top)
		{
			free(a->top);
			a->top = tmp;
			if (tmp)
				tmp = tmp->next;
		}
	}
	return (0);
}

int	chunk_order(t_stack *a, t_stack *b, int num_div, int size_a)
{
	int	rang_in;
	int	range;
	int	rang_fn;
	int	stt;

	stt = 0;
	range = ((size_a - 5) / num_div) + (size_a % 2);
	rang_in = 1;
	rang_fn = range;
	while (a->top && a->size != 5)
	{
		if (a->top->index >= rang_in && a->top->index <= rang_fn)
			push(b, a, 'b');
		else
			move_node(a, best_move_range(a, rang_in, rang_fn, &stt), 'a');
		if (stt == -1)
		{
			stt = 0;
			rang_in = rang_fn + 1;
			rang_fn += ((rang_fn < range * (num_div - 1)) * range) \
			+ ((rang_fn == range * (num_div - 1)) * ((size_a - 5) - rang_fn));
		}
	}
	return (0);
}

int	big_size(t_stack *stack1, t_stack *stack2)
{
	int	num_div;

	num_div = 0;
	num_div += ((stack1->size <= 15) * 3);
	num_div += ((stack1->size <= 100) * 5);
	num_div += ((stack1->size <= 500 && !num_div) * 11);
	num_div += ((stack1->size > 500) * 15);
	chunk_order(stack1, stack2, num_div, stack1->size);
	rondabout(stack1, stack2);
	while (stack2->size != 0)
	{
		best_move(stack2, stack2->size, 'b');
		push(stack1, stack2, 'a');
	}
	return (0);
}

/*************************************************************************
required: sort   3 numbers with <=     3 operations	  < - avg 1,5 - - OK

required: sort   5 numbers with <=    12 operations	  < - avg 7 - - - OK

scored:   sort 100 numbers with <=   700 operations  max score
                                     900 operations  < - avg 794 - - OK
                                    1100 operations
                                    1300 operations
                                    1500 operations  min score

scored:   sort 500 numbers with <=  5500 operations  max score
                                    7000 operations
                                    8500 operations   < - avg 7600- - OK
                                   10000 operations
                                   11500 operations  min score
**************************************************************************/
