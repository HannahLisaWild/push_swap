/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:04:20 by hawild            #+#    #+#             */
/*   Updated: 2023/12/13 15:15:17 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_number_to_str(char *str, int n, int len, int start)
{
	while (len > start)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		start;
	int		len;
	char	*str;

	start = 0;
	len = ft_get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		start = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		start = 1;
	}
	ft_number_to_str(str, n, len, start);
	str[len] = '\0';
	return (str);
}

/*int main()
{
	int n = -2147483648;
	char *result = ft_itoa(n);
	printf("%s\n", result);
	free (result);
}*/