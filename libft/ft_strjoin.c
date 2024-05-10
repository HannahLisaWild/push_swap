/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:50:39 by hawild            #+#    #+#             */
/*   Updated: 2024/04/22 12:52:32 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*joinedstr;

	j = 0;
	i = 0;
	joinedstr = malloc(sizeof(*joinedstr) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joinedstr)
		return (NULL);
	while (s1[j])
	{
		joinedstr[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		joinedstr[j + i] = s2[i];
		i++;
	}
	joinedstr[j + i] = 0;
	return (joinedstr);
}

/*int main()
{
	char *s1 = "whatsssss";
	char    *s2 = "Uppppp";
	char *result = ft_strjoin(s1, s2);
	printf("%s\n", result);
	free(result);
}*/