/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:08:40 by phovsepy          #+#    #+#             */
/*   Updated: 2025/09/07 21:02:33 by phovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		error_check(int argc, char *argv[]);
int		solve_grid(char grid[4][4], char clues[4][4], int row, int col);
int		is_solution_valid(char grid[4][4], char clues[4][4]);
int		is_valid(char grid[4][4], int row, int col, int num);
void	find_nums(char *argv[], char str[4][4]);
void	init_grid(char grid[4][4]);

void	print_grid(char grid[4][4])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j];
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	solve_grid(char grid[4][4], char clues[4][4], int row, int col)
{
	char	num;

	if (row == 4)
		return (is_solution_valid(grid, clues));
	if (col == 4)
		return (solve_grid(grid, clues, row + 1, 0));
	num = '1';
	while (num <= '4')
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_grid(grid, clues, row, col + 1))
				return (1);
			grid[row][col] = '0';
		}
		num++;
	}
	return (0);
}

int	main(int argc, char	*argv[])
{
	char	grid[4][4];
	char	clues[4][4];

	if (!error_check(argc, argv))
		return (0);
	find_nums(argv, clues);
	init_grid(grid);
	if (!solve_grid(grid, clues, 0, 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_grid(grid);
	return (0);
}
