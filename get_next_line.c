/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:41:57 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/16 13:41:49 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (start >= ft_strlen(s))
	{
		ptr = (char *) malloc(1);
		*ptr = '\0';
		return (ptr);
	}
	ptr = (char *) malloc(len + 1);
	if (ptr == 0)
		return ((char *)0);
	while (i < start)
		i++;
	ft_strlcpy(ptr, (s + i), len + 1);
	return (ptr);
}

int     position_ofn(char *str, char c)
{
    int i;

    i = 0;
    while (*str != '\0')
	{
		if (*str == (char)c)
			return (i);
		str++;
	}
	if ((char)c == '\0')
		return (i);
	else
		return (0);
}

int     reader(int fd, char *warehouse)
{
    int readcount;
    int newline;
    char *str;
    char *temp = NULL;

    str = malloc(BUFFER_SIZE * sizeof(char));
    readcount = read(fd, str, BUFFER_SIZE);
    while (readcount > 0)
    {
        if (!temp)
            temp = ft_strdup("");
        temp = ft_strjoin(temp, str);
        newline = ft_strchr(str, '\n');
        printf("newline = %d (|%s|)", newline, str);
        if (newline == 1)
            break;
        str = malloc(BUFFER_SIZE * sizeof(char));
        readcount = read(fd, str, BUFFER_SIZE);
    }
    warehouse = ft_strjoin(warehouse, temp);
    printf("|| %s - %s - %s ||\n", warehouse, temp, str);
    return (readcount);
}

char    *get_next_line(int fd)
{
    static char *warehouse = NULL;
    static int i = 0;
    static int j = 0;
    int readcount;

    if (!warehouse)
        warehouse = ft_strdup("");
    readcount = reader(fd, warehouse);
    j = position_ofn((warehouse + i), '\n');
    i = j + 1;
    return (ft_substr(warehouse, i, j - i));
}

int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	//fd = open("test.txt", O_RDONLY);
	fd = open("test.txt", O_RDONLY);
	while (i < 2)
	{
		printf("%s", get_next_line(fd));
		//get_next_line(fd);
		i++;
	}
}