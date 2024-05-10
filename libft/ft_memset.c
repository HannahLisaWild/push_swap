/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:10:43 by hawild            #+#    #+#             */
/*   Updated: 2023/12/01 14:33:50 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}

/*int     main(void)
{
	unsigned char str[] = "berlin";
	int value = 72;
	char *ptr = ft_memset(str, value, 6);

	printf("%s\n", ptr);
}*/