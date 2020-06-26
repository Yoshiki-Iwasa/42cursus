/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwasa <yiwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:34:08 by yiwasa            #+#    #+#             */
/*   Updated: 2020/06/26 10:06:49 by yiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ultimate_range(char **range, const char *head, const char *foot)
{
	int		i;
	int		k;

	if (head >= foot)
		return (0);
	k = (foot - head);
	*range = (char *)malloc(sizeof(char) * (foot - head) + 1);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < k)
	{
		(*range)[i] = *head;
		head++;
		i++;
	}
	(*range)[i] = '\0';
	return (i);
}

int		count_str(char const *s, char c)
{
	const char		*head;
	const char		*foot;
	int				count;

	head = s;
	foot = s;
	count = 0;
	while (*foot != '\0')
	{
		if (*head == c && head == foot)
		{
			head++;
			foot++;
		}
		else if (*head != c && *foot == c)
		{
			head = foot;
			count++;
		}
		else if (*head != c)
			foot++;
	}
	if (head != foot)
		count++;
	return (count);
}

char	**make_strings(char **strs, const char *head, const char *foot, char c)
{
	int			i;
	const char	*s;

	s = head;
	i = 0;
	while (*foot != '\0')
	{
		if (*head == c && head == foot)
		{
			head++;
			foot++;
		}
		else if (*head != c && *foot == c)
		{
			ft_ultimate_range(strs + i++, head, foot);
			head = foot;
		}
		else if (*head != c && *foot != c)
			foot++;
	}
	if (head != foot)
		ft_ultimate_range(strs + i++, head, foot);
	*(strs + (count_str(s, c))) = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char		**str_array;
	const char	*head;
	const char	*foot;
	int			i;

	head = s;
	foot = s;
	i = 0;
	str_array = malloc(sizeof(char *) * ((count_str(s, c)) + 1));
	if(str_array == 0)
		return (0);
	return (make_strings(str_array, head, foot, c));
}
