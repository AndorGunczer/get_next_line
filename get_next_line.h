/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:44:00 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/23 16:18:52 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

struct  t_list {
    char *warehouse;
    int i;
    int j;
    int freed;
};

char    *get_next_line(int fd);
char    *reader(int fd, char *warehouse, int *readcount);
int 	ft_strchr(const char *s, int c);
unsigned int	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
int     position_ofn(char *str, int i);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
void	ft_bzero(void *s, unsigned int n);
void	*ft_calloc(unsigned int count, unsigned int size);

#endif