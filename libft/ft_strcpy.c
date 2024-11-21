#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
