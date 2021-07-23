/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:41:57 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/23 13:47:23 by agunczer         ###   ########.fr       */
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
		ptr = (char *) ft_calloc(1, sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
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
	return (i);
}

// static char    *returner(char *result)
// {
//     char    str[ft_strlen(result)];
//     ft_strlcpy(str, result, ft_strlen(result) + 1);
//     free(result);
//     return (str);
// }

// static char *output_int(char **str, char *result, int i)
// {
//     if (str [0][i - 1] == '\n')
//         return (result);
//     else if (str[0][i - 1] == '\0')
//     {
//         free(*str);
//         *str = 0;
//         return (result);
//     }
//     else
//     {
//         free(*str);
//         *str = 0;
//         return (NULL);
//     }
// }

char     *reader(int fd, char *warehouse, int *readcount)
{
    int newline;
    char *str;
    char *temp = NULL;

    str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    *readcount = read(fd, str, BUFFER_SIZE);
    if (*readcount == -1 || (*readcount == 0 && !warehouse))
    {
        free(str);
        return (NULL);
    }
    if (!temp)
        temp = ft_strdup("");
    while (*readcount > 0)
    {
        if (!warehouse)
            warehouse = ft_strdup("");
        temp = ft_strjoin(temp, str);
        newline = ft_strchr(str, '\n');
        if (newline == 1)
            break;
        free(str);
        str = calloc(BUFFER_SIZE + 1, sizeof(char));
        *readcount = read(fd, str, BUFFER_SIZE);
    }
    free(str);
    warehouse = ft_strjoin(warehouse, temp);
    free(temp);
    if (!warehouse)
        return (NULL);
    return (warehouse);
}

char    *get_next_line(int fd)
{
    static struct t_list  statics;
    char *result;
    int readcount;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    statics.warehouse = reader(fd, statics.warehouse, &readcount);
	if (readcount == 0 && statics.warehouse == NULL)
		return (NULL);
    if (statics.warehouse == NULL)
		return (NULL);
    statics.j = position_ofn(statics.warehouse, statics.i);
    result = ft_substr(statics.warehouse, statics.i, statics.j - statics.i + 1);
    if (!result || *result == 0)
    {
        free(result);
        if (statics.warehouse)
        {
            free(statics.warehouse);
        }
        return (NULL);
    }
    statics.i = statics.j + 1;
    return (result); //machst du mir nach ?! //Mein gehirn funktioniert nicht mehr //ja da hab ich voll bock drauf
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	//fd = open("test.txt", O_RDONLY);
// 	fd = open("test.txt", O_RDONLY);
// 	while (i < 6)
// 	{
// 		printf("%s", get_next_line(fd));
// 		// get_next_line(fd);
// 		i++;
// 	}
//     fscanf(stdin, "c");
// }
