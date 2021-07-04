/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:16:59 by narakely          #+#    #+#             */
/*   Updated: 2021/06/22 17:07:35 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int		is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static	void	endstart(char const *s1, char const *set, int *end, int *start)
{
	int i;

	i = 0;
	*end = ft_strlen(s1);
	while (s1[i] && is_in_set(s1[i], set))
	{
		(*start)++;
		i++;
	}
	while (*end > *start && is_in_set(s1[*end - 1], set))
		(*end)--;
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		start;
	char	*newstr;

	i = 0;
	end = 0;
	start = 0;
	endstart(s1, set, &end, &start);
	newstr = (char*)malloc(end - start + 1);
	if (newstr == NULL)
		return (NULL);
	while (start < end)
	{
		newstr[i] = s1[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
