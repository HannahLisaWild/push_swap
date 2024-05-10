/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:42 by hawild            #+#    #+#             */
/*   Updated: 2023/12/06 16:57:23 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	destlen;
	size_t			srclen;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	destlen = j;
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstsize <= destlen)
		return (srclen + dstsize);
	while (src [i] != '\0' && i < dstsize - destlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (destlen + srclen);
}

/*int	main(void)
{
	char str[] = "hello";
	char str2[] = "hijfuhgtggtgt";
	ft_strlcat(str, str2, 10);
	printf("%s\n", str);

}*/