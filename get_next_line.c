/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:43:55 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/13 11:11:12 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "../../../LVL1/ft_lib/retrylibft/libft.h"
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *temp;
    temp = ft_strdup("");
    return (reader(fd, temp));
}

int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("42.txt", O_RDONLY);
	// fd = open("big_line_no_nl", O_RDONLY);
	while (i < 3)
	{
		printf("%s", get_next_line(fd));
		//get_next_line(fd);
		i++;
	}
}

// int main(void)
// {
//     // int fd = open("test.txt", O_RDONLY);
//     // char *str;
//     // str = (char *) calloc(100, sizeof(char));
//     // int term = 1;
//     // int i = 0;
//     // while(term != 0)
//     // {
//     //     term = read(fd, &(*(str + i)), BUFFER_SIZE);
//     //     i += term;
//     // }
//     // ft_putstr_fd(str, 1);
//     // close(fd);
// }