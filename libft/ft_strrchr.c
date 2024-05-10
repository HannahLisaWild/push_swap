/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:33:43 by hawild            #+#    #+#             */
/*   Updated: 2023/12/06 17:02:20 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char) c == 0)
	{
		return ((char *)s + i);
	}
	while (i--)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (NULL);
}

/*int main()
{
	char    str[] = "jhjjhjj";
	char    c = 'h';
	char *result = ft_strrchr(str, c);
	if (result != NULL)
	{
		printf(" address of 'h': %p\n", result);
		printf("value at the address: %c\n", *result);
	}
}*/