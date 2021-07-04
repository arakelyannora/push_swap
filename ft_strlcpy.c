/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:20:37 by narakely          #+#    #+#             */
/*   Updated: 2021/06/22 15:43:49 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t sz;
	size_t i;

	i = 0;
	sz = ft_strlen(src);
	if (dstsize == 0)
		return (sz);
	while (i < sz && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sz);
}
