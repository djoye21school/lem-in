/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:46:45 by djoye             #+#    #+#             */
/*   Updated: 2019/11/28 18:34:38 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_strequ(char const *s1, char const *s2)
{
	while (s1 && s2 && *s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 && s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	c;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	c = 0;
	while (s2[c] != '\0')
		c++;
	i = c + i;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*arr;

	if (!*s && !s)
		return (NULL);
	arr = (char*)s;
	while (*arr != c)
	{
		if (*arr == '\0')
			return (NULL);
		arr++;
	}
	return (arr);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && *s)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					sgn;

	nb = 0;
	sgn = 1;
	while (*str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
		sgn = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (sgn == 1 && nb >= 9223372036854775807)
		return (-1);
	else if (sgn == -1 && nb > 9223372036854775807)
		return (0);
	return (nb * sgn);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}