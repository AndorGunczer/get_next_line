/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:02:20 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/23 17:33:56 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	unsigned int	i;
	void	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
	{
        free (ptr);
		return ((void *)0);
	}
	while (i < count * size)
	{
		*(char *)(ptr + i) = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	i = 0;
	ptr = (char *) calloc(len + 1, sizeof(char));
	if (ptr == NULL)
	{
        free(ptr);
        return ((void *)0);
    }
	while (i < len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

int 	ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	// if (*s == c)
	// {
	// 	return (1);
	// }
	// else
	// {
		return (0);
	// }
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (ptr == 0)
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	while (*(s2) != '\0')
	{
		*(ptr + i) = *(s2);
		s2++;
		i++;
	}
	*(ptr + i) = '\0';
    free((void *)s1);
	return (ptr);
}

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	if (i < dstsize && *(char *)(src + i) != '\0')
	{
		while (*(char *)(src + i) != '\0' && i < dstsize - 1)
		{
			*(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	if (i < dstsize)
		*(dst + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n != 0 && i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}