/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:11:17 by phovsepy          #+#    #+#             */
/*   Updated: 2025/09/07 20:59:16 by phovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(char line[4]);

int	check_row(char grid[4][4], char clues[4][4], int row)
{
	char	line[4];
	int		visible;
	int		i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i] - '0';
		i++;
	}
	visible = count_visible(line);
	if (visible != (clues[2][row] - '0'))
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][3 - i] - '0';
		i++;
	}
	visible = count_visible(line);
	if (visible != (clues[3][row] - '0'))
		return (0);
	return (1);
}

int	check_col(char grid[4][4], char clues[4][4], int col)
{
	char	line[4];
	int		visible;
	int		i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col] - '0';
		i++;
	}
	visible = count_visible(line);
	if (visible != (clues[0][col] - '0'))
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[3 - i][col] - '0';
		i++;
	}
	visible = count_visible(line);
	if (visible != (clues[1][col] - '0'))
		return (0);
	return (1);
}

int	count_visible(char line[4])
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	is_solution_valid(char grid[4][4], char clues[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row(grid, clues, i) || !check_col(grid, clues, i))
			return (0);
		i++;
	}
	return (1);
}
