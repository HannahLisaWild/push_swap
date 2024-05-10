/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:52:02 by hawild            #+#    #+#             */
/*   Updated: 2023/12/12 14:58:07 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	apply_to_s(unsigned int i, char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + ('a' - 'A');
	}
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;
	int				len;

	if (s == NULL && f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (new_str);
}

/*int	main(void)
{
	char (*f)(unsigned int i, char c) = &apply_to_s;
	const char s[] = "HELLO";
	char *new_str = ft_strmapi(s, f);

	printf("%s\n", new_str);
	free(new_str);
	return (0);
}*/