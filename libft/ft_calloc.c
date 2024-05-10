/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:06:42 by hawild            #+#    #+#             */
/*   Updated: 2023/12/01 14:32:02 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, (nmemb * size));
		return (ptr);
	}
	return (NULL);
}

/*int main()
{
	size_t i = 0;
	// Test case 1: Allocate memory for an array of integers
	int *int_array = (int *)ft_calloc(6, sizeof(int));

	if (int_array != NULL)
	{
		// Use the allocated memory
		while ( i < 6)
		{
			printf("%d ", int_array[i]);
			i++;
		}
		printf("\n");

		// Free the allocated memory
		free(int_array);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
}*/