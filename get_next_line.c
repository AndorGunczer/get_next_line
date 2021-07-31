/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:41:57 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/31 14:10:10 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int     position_ofn(char *str, int i, int goal)
{
    if (goal == 1)
    {
        while (*(str + i) != '\0')
	    {
		    if (*(str + i) == '\n')
			    return (i);
		    i++;
	    }
	    return (i);
    }
    else if (goal == 2)
    {
        while (*str != '\0')
	    {
		    if (*str == '\n')
			    return (1);
		    str++;
	    }
	    return (0);
    }
    else
        return (0);
}

static char *output_int(char **str, char *result, int i)
{
    if (str[0][i] == '\n')
        return (result);
    else if (str[0][i] == '\0')
    {
        free(*str);
        *str = 0;
        return (result);
    }
    else
    {
        free(*str);
        *str = 0;
        return (NULL);
    }
}

char    *reader_helper(int fd, int *readcount, char *temp, int *newline, char *str)
{
    while (*readcount > 0)
    {
        temp = ft_strjoin(temp, str);
        *newline = position_ofn(str, 0, 2);
        if (*newline == 1)
            break;
        if (str)
            free(str);
        str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
        *readcount = read(fd, str, BUFFER_SIZE);
    }
    free(str);
    return (temp);
}

char    *reader(int fd, char *warehouse, int *readcount)
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
    if (!warehouse && readcount > 0)
        warehouse = ft_strdup("");
    temp = reader_helper(fd, readcount, temp, &newline, str);
    warehouse = ft_strjoin(warehouse, temp);
    if (temp != NULL)
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
	if (readcount == 0 && !statics.warehouse)
		return (NULL);
    if (!statics.warehouse)
		return (NULL);
    statics.j = position_ofn(statics.warehouse, statics.i, 1);
    result = ft_substr(statics.warehouse, statics.i, statics.j - statics.i + 1);
    statics.i = statics.j + 1;
    return (output_int(&statics.warehouse, result, statics.j));
}

//  int	main(void)
//  {
//  	int		fd;
//  	int		i;

//  	i = 0;
//  	//fd = open("test.txt", O_RDONLY);
//  	fd = open("test.txt", O_RDONLY);
//  	while (i < 10)
//  	{
//  		printf("%s", get_next_line(fd));
//  		// get_next_line(fd);
//  		i++;
//  	}
//     fscanf(stdin, "c");
//  }
