#define _POSIX_C_SOURCE 200809L

#include "bsq.h"
#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static int	min3(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}

static int	is_valid_map(t_map *m)
{
	int	i;
	int	j;

	if (!m || !m->grid || m->rows < 1 || m->cols < 1)
		return (0);
	if (m->empty == m->obs || m->empty == m->full || m->obs == m->full)
		return (0);
	i = 0;
	while (i < m->rows)
	{
		if (!m->grid[i] || ft_strlen(m->grid[i]) != m->cols)
			return (0);
		j = 0;
		while (j < m->cols)
		{
			if (m->grid[i][j] != m->empty && m->grid[i][j] != m->obs)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	parse_header(char *line, t_map *m)
{
	int		i;
	int		rows;
	char	e;
	char	o;
	char	f;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	rows = 0;
	while (line[i] >= '0' && line[i] <= '9')
		rows = rows * 10 + (line[i++] - '0');
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (rows < 1 || !line[i] || !line[i + 1] || !line[i + 2])
		return (0);
	e = line[i++];
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i] || !line[i + 1])
		return (0);
	o = line[i++];
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i])
		return (0);
	f = line[i];
	m->rows = rows;
	m->empty = e;
	m->obs = o;
	m->full = f;
	return (1);
}

int	read_map(FILE *fp, t_map *m)
{
	char	*line;
	size_t	len;
	int		i;
	int		j;

	line = NULL;
	len = 0;
	m->grid = NULL;
	m->cols = 0;
	if (getline(&line, &len, fp) <= 0)
	{
		free(line);
		return (0);
	}
	if (!parse_header(line, m))
	{
		free(line);
		return (-1);
	}
	free(line);
	line = NULL;
	m->grid = (char **)malloc(sizeof(char *) * m->rows);
	if (!m->grid)
		return (-1);
	i = 0;
	while (i < m->rows)
	{
		if (getline(&line, &len, fp) <= 0)
			return (-1);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (i == 0)
			m->cols = ft_strlen(line);
		else if (ft_strlen(line) != m->cols)
			return (-1);
		m->grid[i] = (char *)malloc(m->cols + 1);
		if (!m->grid[i])
			return (-1);
		j = 0;
		while (j <= m->cols)
		{
			m->grid[i][j] = line[j];
			j++;
		}
		free(line);
		line = NULL;
		i++;
	}
	if (!is_valid_map(m))
		return (-1);
	return (1);
}

int	solve_bsq(t_map *m)
{
	int		*dp;
	int		i;
	int		j;
	int		s;
	int		best;
	int		br;
	int		bc;
	int		tr;
	int		tc;
	int		v;

	dp = (int *)malloc(sizeof(int) * m->rows * m->cols);
	if (!dp)
		return (0);
	best = 0;
	br = 0;
	bc = 0;
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			if (m->grid[i][j] == m->obs)
				dp[i * m->cols + j] = 0;
			else if (i == 0 || j == 0)
				dp[i * m->cols + j] = 1;
			else
			{
				v = min3(dp[(i - 1) * m->cols + j],
						dp[i * m->cols + j - 1],
						dp[(i - 1) * m->cols + j - 1]);
				dp[i * m->cols + j] = v + 1;
			}
			s = dp[i * m->cols + j];
			tr = i - s + 1;
			tc = j - s + 1;
			if (s > best || (s == best && (tr < br || (tr == br && tc < bc))))
			{
				best = s;
				br = tr;
				bc = tc;
			}
			j++;
		}
		i++;
	}
	free(dp);
	if (best < 1)
		return (1);
	i = br;
	while (i < br + best)
	{
		j = bc;
		while (j < bc + best)
		{
			m->grid[i][j] = m->full;
			j++;
		}
		i++;
	}
	return (1);
}

void	print_map(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->rows)
	{
		fprintf(stdout, "%s\n", m->grid[i]);
		i++;
	}
}

void	free_map(t_map *m)
{
	int	i;

	if (!m)
		return ;
	if (m->grid)
	{
		i = 0;
		while (i < m->rows)
		{
			free(m->grid[i]);
			i++;
		}
		free(m->grid);
	}
	m->grid = NULL;
	m->rows = 0;
	m->cols = 0;
}

static void	process_stream(FILE *fp)
{
	t_map	map;
	int		status;

	while (1)
	{
		status = read_map(fp, &map);
		if (status == 0)
			break ;
		if (status == -1 || !solve_bsq(&map))
			fprintf(stderr, "map error\n");
		else
			print_map(&map);
		free_map(&map);
	}
}

int	main(int ac, char **av)
{
	FILE	*fp;
	int		i;

	if (ac < 2)
	{
		process_stream(stdin);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		fp = fopen(av[i], "r");
		if (!fp)
		{
			fprintf(stderr, "map error\n");
			i++;
			continue ;
		}
		process_stream(fp);
		fclose(fp);
		i++;
	}
	return (0);
}
