/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:40:19 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/16 20:02:45 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Cosas malas: Esta ordenado, duplicadas.
// int MAX o MIN.
// tiene caracteres que no sean numeros, no mas de un signo. 
int	is_dupped(int *array, int len)
{
	int	i;
	int	j;
	int	*tmp;

	tmp = malloc(len * sizeof(int));
	if (!tmp)
		exit((ft_fd_printf(2, "Error\n") * 0) + 1);
	tmp[0] = array[0];
	i = 0;
	while (++i < len)
	{
		j = -1;
		while (++j < i)
		{
			if (array[i] == tmp[j])
			{
				free(tmp);
				return (0);
			}
		}
		tmp[i] = array[i];
	}
	free(tmp);
	return (1);
}

int	limits_error(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	simpl_nmb[13];

	i = 0;
	while (++i < argc)
	{
		j = -1;
		k = 0;
		ft_bzero(simpl_nmb, 13);
		if (argv[i][0] == '+' || argv[i][0] == '-')
			if (argv[i][0] == '-')
				simpl_nmb[k++] = argv[i][++j];
		while (argv[i][++j] == '0')
			;
		while (argv[i][j] != '\0' && k < 13)
			simpl_nmb[k++] = argv[i][j++];
		if ((simpl_nmb[0] == '-' && ((k == 11 && ft_strncmp \
			(simpl_nmb, "-2147483648", 12) > 0) || k > 11)) \
			|| (simpl_nmb[0] != '-' && ((k == 10 && ft_strncmp \
					(simpl_nmb, "2147483647", 11) > 0) || k > 10)))
			return (0);
	}
	return (1);
}

int	syntax_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
		while (argv[i][++j] != '\0')
			if ((argv[i][j] < '0' || argv[i][j] > '9') \
			&& (argv[i][j] != '+' || argv[i][j] != '-'))
				return (0);
		if ((j == 1 && (argv[i][0] == '+' || argv[i][0] == '-')) || !*argv[i])
			return (0);
	}
	return (1);
}

int	parsing(int argc, char **argv)
{
	int	*numbers;
	int	i;

	i = 0;
	if (argc == 1)
		exit (0);
	numbers = malloc(argc * sizeof(int));
	if (!numbers)
		exit ((ft_fd_printf(2, "Error\n") * 0) + 1);
	if (!(syntax_error(argc, argv) && limits_error(argc, argv)))
		exit ((ft_fd_printf(2, "Error\n") * 0) + 1);
	while (++i < argc)
		numbers[i - 1] = ft_atoi(argv[i]);
	if (!is_dupped(numbers, argc - 1))
		exit ((ft_fd_printf(2, "Error\n") * 0) + 1);
	if (argc == 2)
		exit (0);
	free(numbers);
	return (1);
}
/*
int main(int argc, char **argv)
{
	printf("LO QUE DEVUELVE: %d\n", parsing(argc, argv));
	return 0;
}*/
