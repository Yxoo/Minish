#include "minishell.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		src_len;
	int		i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	i = 0;
	str = ft_calloc(sizeof(char), src_len + 1);
	if (str == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}