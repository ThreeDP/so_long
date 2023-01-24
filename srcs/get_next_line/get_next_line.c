/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:47:22 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/23 19:05:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < (size -1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}

/*
Copy the structure data to a single array
and return the line.						*/
static char	*create_line(t_list **lst, size_t line_size)
{
	char	*line;
	t_list	*list;
	size_t	i;
	size_t	len_line;

	list = *lst;
	line = (char *) malloc(line_size * sizeof(char) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < (line_size + 1) * sizeof(char))
		line[i++] = '\0';
	while (list)
	{
		i = 0;
		len_line = get_strlen(line);
		if ((line_size + 1) <= len_line)
			break ;
		while ((list-> content)[i] && (len_line + 1) < (line_size + 1))
			line[len_line++] = (list-> content)[i++];
		line[len_line] = '\0';
		list = list-> next;
	}
	return (line);
}

int	valid(int fd, char **buf, t_list **lst)
{
	int	byte;

	byte = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0);
	if (!(*buf))
	{
		(*buf) = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
		if (!(*buf))
			return (0);
		while (byte < (BUFFER_SIZE + 1))
			(*buf)[byte++] = 0;
	}
	get_lstadd_back(lst, 1);
	if (!(*lst))
		return (free((*buf)), 0);
	return (1);
}

/*
Populate and create new nodes with characters from
the file while not finding a \n character or the
end of the file			*/
static size_t	make_pieces(int fd, char *buf, t_list **lst, size_t bsr)
{
	size_t	line_size;
	char	*c_pos;
	char	*tmp;

	line_size = 0;
	while (1)
	{
		c_pos = get_strchr(buf, '\n');
		if (c_pos)
			bsr = (c_pos - buf) + 1;
		line_size += bsr;
		(*lst)->content = get_strdup(buf, bsr);
		if (c_pos)
			break ;
		bsr = read(fd, buf, BUFFER_SIZE);
		buf[bsr] = '\0';
		if (!bsr)
			return (line_size);
		get_lstadd_back(lst, 0);
		(*lst) = (*lst)->next;
	}
	tmp = get_strdup(&buf[bsr], get_strlen(&buf[bsr]));
	get_strlcpy(buf, tmp, get_strlen(tmp) + 1);
	free(tmp);
	return (line_size += bsr);
}

char	*get_next_line(int fd)
{
	t_list		*lst;
	t_list		*ret;
	char		*line;
	size_t		bsr;
	static char	*buf;

	line = NULL;
	if (!valid(fd, &buf, &lst))
		return (NULL);
	ret = lst;
	bsr = get_strlen(buf);
	if (!bsr)
		bsr = read(fd, buf, BUFFER_SIZE);
	buf[bsr] = '\0';
	bsr = make_pieces(fd, buf, &lst, bsr);
	if (bsr)
		line = create_line(&ret, bsr);
	else
	{
		free(buf);
		buf = NULL;
	}
	get_lstclear(&ret, free);
	return (line);
}
