/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:55:23 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/30 15:03:45 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		index;
	char		*new_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc((s1_len + s2_len) + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		new_str[index] = s1[index];
		index++;
	}
	while (*s2 != '\0')
		new_str[index++] = *s2++;
	new_str[index] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*str;

	str = (char *)s;
	index = 0;
	while (index < n)
		str[index++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_mem;
	size_t	size_alloc;

	size_alloc = size * count;
	if (count > 0 && size > 0)
		if (size_alloc % count != 0 || size_alloc % size != 0)
			return (NULL);
	alloc_mem = (void *)malloc(sizeof(char) * size_alloc);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, size_alloc);
	return (alloc_mem);
}
