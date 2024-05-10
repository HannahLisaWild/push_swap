/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:13:47 by hawild            #+#    #+#             */
/*   Updated: 2023/12/12 16:20:09 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i < start)
	{
		return (ft_strdup(""));
	}
	else if (ft_strlen(s + start) < len && len != 0)
		len = ft_strlen(s + start);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

/*int main()
{
	char *s = "Hellolalala";
	char *result = ft_substr(s, 4, 5);
	printf("%s\n", result);
	free (result);
}*/