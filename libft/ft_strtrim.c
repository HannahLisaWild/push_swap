/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:13 by hawild            #+#    #+#             */
/*   Updated: 2023/12/13 15:18:32 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmedstr;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_char_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_set(s1[end - 1], set))
		end--;
	trimmedstr = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!trimmedstr)
		return (NULL);
	i = 0;
	while (start < end)
		trimmedstr[i++] = s1[start++];
	trimmedstr[i] = 0;
	return (trimmedstr);
}

/*int main()
{
	char *s1 = "H1b2Cc3c333111121c3";
	char *set = "1H2C3";
	char    *result = ft_strtrim(s1, set);
	printf("%s\n", result);
	free (result);
}*/