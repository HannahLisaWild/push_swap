/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:58:22 by hawild            #+#    #+#             */
/*   Updated: 2023/12/04 18:50:32 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	apply_to_s(unsigned int i, char *s)
{
	(void *) i;
	if (*s >= 'A' && *s <= 'Z')
	{
		*s = *s + ('a' - 'A');
	}
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s != NULL && f != NULL)
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	void	(*f)(unsigned int i, char *s);
	char	s[] = "HELLO";

	f = &apply_to_s;
	ft_striteri(s, f);
	printf("%s\n", s);
	return (0);
}*/