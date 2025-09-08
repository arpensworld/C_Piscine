/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:46:37 by phovsepy          #+#    #+#             */
/*   Updated: 2025/09/07 19:48:15 by phovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	error_check(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (argv[1][i])
	{
		if ((i % 2 == 0 && (argv[1][i] < '1' || argv[1][i] > '4')) ||
			(i % 2 == 1 && argv[1][i] != ' '))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (i != 31)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	find_nums(char	*argv[], char str[4][4])
{
	int	k;
	int	i;
	int	j;

	k = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			str[i][j] = argv[1][k];
			j++;
			k += 2;
		}
		str[i][j] = '\0';
		i++;
	}
}

int	is_valid(char grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	init_grid(char grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = '0';
			j++;
		}
		i++;
	}
}
