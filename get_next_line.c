#include "get_next_line.h"

char	*save(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
		return (NULL);
	new_store = (char *)malloc(sizeof(char) * (ft_strlen(store) - i));
	if (!new_store)
		return (NULL);
	i++;
	j = 0;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = '\0';
	return (new_store);
}

char	*ft_line(char *store)
{
	int		i;
	char	*line;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		line[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		line[i] = store[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_and_save(int fd, char *store)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (ft_strchr(store, '\n') == NULL && bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buf[bytes_read] = '\0';
		store = ft_strjoin(store, buf);
	}
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;
	char		*tmp;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	store = read_and_save(fd, store);
	if (!store)
		return (NULL);
	tmp = store;
	line = ft_line(tmp);
	store = save(tmp);
	free(tmp);
	return (line);
}