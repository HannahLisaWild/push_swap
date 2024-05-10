/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:38 by hawild            #+#    #+#             */
/*   Updated: 2023/12/12 16:20:41 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	while (n--)
	{
		dest_ptr[n] = src_ptr[n];
	}
	return (dest);
}

/*int	main(void)
{
	char dest[] = "berlin";
	char src[] = "333";
	ft_memcpy(dest, src, 3);
	printf("%s\n", dest);
}*/