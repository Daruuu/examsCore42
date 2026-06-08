#define _POSIX_C_SOURCE 200809L

#include "bsq.h"
#include <stdlib.h>

#define MIN3(a,b,c) ((a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c)))

static int	slen(char *s)
{
	int i = 0;
	while (s[i]) i++;
	return (i);
}

static void	free_m(t_map *m)
{
	int i = 0;
	while (i < m->r)
		free(m->g[i++]);
	free(m->g);
	m->g = 0;
}

static int	hdr(char *ln, t_map *m)
{
	int i = 0, r = 0;

	while (ln[i] == ' ' || ln[i] == '\t') i++;
	while (ln[i] >= '0' && ln[i] <= '9')
		r = r * 10 + (ln[i++] - '0');
	while (ln[i] == ' ' || ln[i] == '\t') i++;
	if (r < 1 || !ln[i] || !ln[i + 1] || !ln[i + 2])
		return (0);
	m->r = r;
	m->e = ln[i++];
	while (ln[i] == ' ' || ln[i] == '\t') i++;
	if (!ln[i] || !ln[i + 1])
		return (0);
	m->o = ln[i++];
	while (ln[i] == ' ' || ln[i] == '\t') i++;
	if (!ln[i])
		return (0);
	m->f = ln[i];
	return (m->e != m->o && m->e != m->f && m->o != m->f);
}

static int	read_m(FILE *fp, t_map *m)
{
	char	*ln = 0;
	size_t	n = 0;
	int		i, j, l;

	m->g = 0;
	if (getline(&ln, &n, fp) <= 0)
	{
		free(ln);
		return (0);
	}
	if (!hdr(ln, m))
	{
		free(ln);
		return (-1);
	}
	free(ln);
	ln = 0;
	m->g = malloc(sizeof(char *) * m->r);
	if (!m->g)
		return (-1);
	i = 0;
	while (i < m->r)
	{
		if (getline(&ln, &n, fp) <= 0)
			return (-1);
		l = slen(ln);
		if (l && ln[l - 1] == '\n')
			ln[--l] = 0;
		if (!i)
			m->c = l;
		else if (l != m->c)
			return (-1);
		if (m->c < 1)
			return (-1);
		m->g[i] = malloc(m->c + 1);
		j = -1;
		while (++j < m->c)
		{
			if (ln[j] != m->e && ln[j] != m->o)
				return (-1);
			m->g[i][j] = ln[j];
		}
		m->g[i][j] = 0;
		free(ln);
		ln = 0;
		i++;
	}
	return (1);
}

static void	solve(t_map *m)
{
	int *dp, i, j, b = 0, br = 0, bc = 0, tr, tc, v;

	dp = malloc(sizeof(int) * m->r * m->c);
	i = -1;
	while (++i < m->r)
	{
		j = -1;
		while (++j < m->c)
		{
			if (m->g[i][j] == m->o)
				v = 0;
			else if (!i || !j)
				v = 1;
			else
				v = 1 + MIN3(dp[(i - 1) * m->c + j],
					dp[i * m->c + j - 1], dp[(i - 1) * m->c + j - 1]);
			dp[i * m->c + j] = v;
			tr = i - v + 1;
			tc = j - v + 1;
			if (v > b || (v == b && (tr < br || (tr == br && tc < bc))))
				b = v, br = tr, bc = tc;
		}
	}
	free(dp);
	if (b < 1)
		return ;
	i = br - 1;
	while (++i < br + b)
	{
		j = bc - 1;
		while (++j < bc + b)
			m->g[i][j] = m->f;
	}
}

static void	run(FILE *fp)
{
	t_map	m;
	int		st;
	int		i;

	while (1)
	{
		st = read_m(fp, &m);
		if (!st)
			break ;
		if (st < 0)
			fprintf(stderr, "map error\n");
		else
		{
			solve(&m);
			i = 0;
			while (i < m.r)
				fprintf(stdout, "%s\n", m.g[i++]);
		}
		if (m.g)
			free_m(&m);
	}
}

int	main(int ac, char **av)
{
	FILE *fp;
	int i = 0;

	if (ac < 2)
		run(stdin);
	else
		while (++i < ac)
		{
			fp = fopen(av[i], "r");
			if (!fp)
				fprintf(stderr, "map error\n");
			else
			{
				run(fp);
				fclose(fp);
			}
		}
	return (0);
}
