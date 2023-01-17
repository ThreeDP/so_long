/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:50:43 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/08 20:59:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_bit(char **s, char *n)
{
	if (n && (n - (*s)) == 0)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

size_t	count_words(char *s, char c, size_t amount)
{
	char	*next;

	next = NULL;
	while (1)
	{
		next = ft_strchr(s, c);
		if (next && (next - s) > 0 && ft_strlen(s) > (size_t)(next - s))
		{
			s += (next - s) + 1;
			amount++;
			continue ;
		}
		if (next_bit(&s, next))
			continue ;
		if (ft_strlen(s))
			amount++;
		break ;
	}
	return (amount);
}

void	make_split(char **split, char *s, char c)
{
	size_t	i;
	char	*next;

	i = 0;
	next = NULL;
	while (1)
	{
		next = ft_strchr(s, c);
		if (next && (next - s) > 0 && ft_strlen(s) > (size_t)(next - s))
		{
			split[i++] = ft_strndup(s, (next - s));
			s += (next - s) + 1;
			continue ;
		}
		if (next_bit(&s, next))
			continue ;
		if (ft_strlen(s))
			split[i++] = ft_strdup(s);
		break ;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**split;

	size = 0;
	if (!s || !*s)
		return (ft_calloc(1, sizeof(char **)));
	size = count_words((char *)s, c, size);
	split = (char **) ft_calloc(size + 1, sizeof(char *));
	if (!split)
		return (split);
	make_split(split, (char *)s, c);
	return (split);
}
