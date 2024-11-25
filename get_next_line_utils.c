#include "get_next_line.h"


size_t ft_strlen(const char* str)
{
	size_t i;
    i = 0;
    if (!str)
        return NULL;    
    while (str[i])
        i++;
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    int i;
    i = 0;

    if (!s)
        return NULL;  
    char ch = (char)c;
    while (s[i] != '\0')
    {
        if (s[i] == ch)
            return (s + i);
        i++;
    }
    
    if (s[i] == ch)
        return (s + i);

    return NULL;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    size_t str_len;
    char *substr;

    str_len = ft_strlen(s);
    i = 0;
    
    if (!s)
        return (NULL);
    if (start >= str_len)
        return ("");

    if (len > str_len - start)
        len = str_len - start;
    
    substr = malloc(len + 1);
    if (!substr)
        return (NULL);
    
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';

    return (substr);
}
