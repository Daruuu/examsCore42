#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	dup = (char *) malloc(sizeof (char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_read;
	static int	buffer_pos;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if(buffer_read <= 0)
				break;
		}
		if (line[i] == '\n')
			break;
		line[i] = buffer[buffer_pos++];
		i++;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(void)
{
	int	fd = open("abc.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error open file");
		return (1);
	}
	char	*line = NULL;
	line = get_next_line(fd);
	int	i = 0;
	while (line && i <= 5)
	{
		printf("%s\n", line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}
