
#include "get_next_line.h"


size_t ft_strlen(const char* str)
{
	size_t i;
    i = 0;
    if (!str)
        return (0);    
    while (str[i])
        i++;
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    if (c == '\0')
        return ((char *)&s[ft_strlen(s)]);
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return ((char *)(s + i));
        i++;
    }

    return (0);
}

char *ft_strjoin(char *left_over, char *buffer)
{
    size_t i;
    size_t j;
    char *str;
    
    i = -1;
    j = 0;
    if (!left_over)
    {
        left_over = (char *)malloc(1);
        if (!left_over)
            return (NULL);
        left_over[0]='\0';
    }
    if (!left_over || !buffer)
        return (NULL);
    str = malloc((ft_strlen(left_over) + ft_strlen(buffer))+1);
    if (!str)
        return (NULL);
    while (left_over[++i])
        str[i] = left_over[i];
    while (buffer[j])
        left_over[j++] = buffer[i++];
    str[(ft_strlen(left_over) + ft_strlen(buffer))] = '\0';
    free(left_over);
    return str;
}
