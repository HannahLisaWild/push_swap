/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:37:55 by hawild            #+#    #+#             */
/*   Updated: 2023/12/01 14:33:32 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	size_t			i;

	i = 0;
	s_ptr = (unsigned char *)s;
	while (i < n)
	{
		if (s_ptr[i] == (unsigned char)c)
		{
			return (s_ptr + i);
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	char str[] = "ferdhinand";
	char c = 'h';
	char *result = ft_memchr(str, c, 5);

	if (result != NULL)
	{
		printf("Address of 'h': %p\n", (void *)result);
		printf("Value at the address: %c\n", *result);
	}
	else
	{
		printf("Character not found in the string.\n");
	}

	return (0);
}*/
