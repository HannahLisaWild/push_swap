/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:03:25 by hawild            #+#    #+#             */
/*   Updated: 2023/12/12 16:19:17 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;

	dest2 = dest;
	src2 = src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest2 < src2)
	{
		while (n--)
		{
			*dest2++ = *src2++;
		}
	}
	else
	{
		dest2 += n;
		src2 += n;
		while (n--)
		{
			*--dest2 = *--src2;
		}
	}
	return (dest);
}

/*int main()
{
	char src_str[] = "hello111111";
	char dest_str[] = "42berlin";
	ft_memmove(dest_str, src_str, 7);
	printf("%s\n", dest_str);
}*/