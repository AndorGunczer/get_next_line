/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:43:57 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/14 14:58:12 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LVL1/ft_lib/retrylibft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int    gnl_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (*(s + i) != '\0')
    {
        if (*(s + i) == (char)c)
            return (i);
        i++;
    }
    if (*(s + i) == '\0')
    {
        return (0);
    }
    else
    {
        return (0);
    }
}

char	*gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		return (0);
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
	return (dst);
}

char     *only_print(char *ptr)
{
    int i;
    char *str;

    i = gnl_strchr(ptr, '\n');
    str = ft_calloc(i, sizeof(char));
    ft_strlcpy(str, ptr, i);
    ptr++;
    return (str);
}

char    *reader(int fd, char *temp)
{
    int newline;
    char *str;
    char *returnable;
    int j;
    static int i;

    str = malloc(1000 * sizeof(char));
    while (read(fd, str, BUFFER_SIZE) > 0)
    {
        printf("\n%s\n", str);
        str[BUFFER_SIZE] = '\0';
        temp = ft_strjoin(temp, str);
        if ((newline = gnl_strchr(str, '\n')))
            break;
    }
    j = gnl_strchr(temp, '\n');
    returnable = ft_calloc(j, sizeof(char));
    gnl_strlcpy(returnable, temp + i, j + 1);
    // if (gnl_strchr(temp + j + 1))
    // {

    // }
    return (returnable);
}


/*
        else
        {
            j = gnl_strchr(temp, '\n');
            str = ft_calloc(j, sizeof(char));
            gnl_strlcpy(str, temp + i, j);
            i = j + 1;
            return (str);
        }
*/