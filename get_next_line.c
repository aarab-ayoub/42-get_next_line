#include "get_next_line.h"

static char *ft_line(char *leftover)
{
    int i = 0;
    char *line;

    if (!leftover)
        return (NULL);
    while (leftover[i] && leftover[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (leftover[i] && leftover[i] != '\n')
    {
        line[i] = leftover[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

static char *ft_save(char *leftover)
{
    int i = 0;
    int j = 0;
    char *new_leftover;

    while (leftover[i] && leftover[i] != '\n')
        i++;
    if (!leftover[i])
    {
        free(leftover);
        return (NULL);
    }
    new_leftover = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - i + 1));
    if (!new_leftover)
        return (NULL);
    i++;
    while (leftover[i])
        new_leftover[j++] = leftover[i++];
    new_leftover[j] = '\0';
    free(leftover);
    return (new_leftover);
}

char *get_next_line(int fd)
{
    char *buffer;
    static char *leftover;
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(leftover, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        leftover = ft_strjoin(leftover, buffer);
    }
    free(buffer);
    line = ft_line(leftover);
    leftover = ft_save(leftover);
    return (line);
}