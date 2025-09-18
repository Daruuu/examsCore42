/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void  flood(char **tab, t_point size, t_point begin, char to_find)
{
	if (begin.y < 0 || begin.y >= size.y \
		|| begin.x < 0 || begin.x >= size.x \
		|| tab[begin.y][begin.x] != to_find)
		return ;
	tab[begin.y][begin.x] = 'F';
	flood(tab, size, (t_point){begin.x - 1, begin.y}, to_find);
	flood(tab, size, (t_point){begin.x + 1, begin.y}, to_find);
	flood(tab, size, (t_point){begin.x, begin.y - 1}, to_find);
	flood(tab, size, (t_point){begin.x, begin.y + 1}, to_find);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	flood(tab, size, begin, tab[begin.y][begin.x]);
}
