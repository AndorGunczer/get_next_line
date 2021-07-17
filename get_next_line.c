/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:41:57 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/17 11:49:16 by agunczer         ###   ########.fr       */
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

int     position_ofn(char *str, int i)
{
    while (*(str + i) != '\0')
	{
		if (*(str + i) == '\n')
			return (i);
		i++;
	}
	if (*(str + i) == '\n' || *(str + i) == '\0')
	{
		return (i);
	}
	else
	{
		return (0);
	}
}

// static int	where_is_n(char *str, int *i)
// {
// 	int	j;

// 	j = *i;
// 	while (str[j] != '\0')
// 	{
// 		if (str[j] == '\n')
// 		{
// 			*i = j;
// 			return (j);
// 		}
// 		j++;
// 		if (str[j] == '\0')
// 		{
// 			*i = j;
// 			return (j);
// 		}
// 	}
// 	return (0);
// }

char     *reader(int fd, char *warehouse, int *readcount)
{
    int newline;
    char *str;
    char *temp = NULL;

    str = malloc(BUFFER_SIZE + 1 * sizeof(char));
    *readcount = read(fd, str, BUFFER_SIZE);
    if (!temp)
        temp = ft_strdup("");
    while (*readcount > 0)
    {
        if (!temp)
            temp = ft_strdup("");
        temp = ft_strjoin(temp, str);
        newline = ft_strchr(str, '\n');
        if (newline == 1)
            break;
        str = malloc(BUFFER_SIZE * sizeof(char));
        *readcount = read(fd, str, BUFFER_SIZE);
    }
    return (ft_strjoin(warehouse, temp));
}

char    *get_next_line(int fd)
{
    printf("!!!!!!!!THIS IS STARTA!!!!!!!!");
    static char *warehouse = NULL;
    static int i = 0;
    static int j = 0;
    int k;
    int readcount = 1;

    if (!warehouse)
        warehouse = ft_strdup("");
    if (readcount != 0)
        warehouse = reader(fd, warehouse, &readcount);
    j = position_ofn(warehouse, i);
    k = i;
    i = j + 1;
    // printf("k: %d - i: %d - j: %d", k, i, j); //ja da hab ich voll bock drauf
    return (ft_substr(warehouse, k, j - k)); //machst du mir nach ?! //Mein gehirn funktioniert nicht mehr
}

int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	//fd = open("test.txt", O_RDONLY);
	fd = open("test.txt", O_RDONLY);
	while (i < 1)
	{
		printf("\t-->LINE: %s\n", get_next_line(fd));
		// get_next_line(fd);
		i++;
	}
}