/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:43:57 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/13 14:39:45 by agunczer         ###   ########.fr       */
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
        return (1);
    }
    else
    {
        return (0);
    }
}

char    *reader(int fd, char *temp)
{
    int readcount;
    int newline;
    char *str;
    int instadel = 0;

    // str = ft_calloc(BUFFER_SIZE, sizeof(char));
    str = malloc(BUFFER_SIZE * sizeof(char));
    while (!newline)
    {
        read(fd, str, BUFFER_SIZE);
        // printf("%s", str);
        newline = gnl_strchr(str, '\n');
        temp = ft_strjoin(temp, str);
        // printf("%s", ft_strjoin(temp, str));
    }
    // ft_split(temp, '\n');
    return (temp);
}
