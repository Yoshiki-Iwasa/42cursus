/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwasa <yiwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:30:25 by yiwasa            #+#    #+#             */
/*   Updated: 2020/06/28 18:34:20 by yiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//////これ、ファイルの中にヌルが入ってた場合はどうするんだろか。。。。。
//////mallocがおきて、その内容が破棄されるたびに、freeしないと

int		pattern_rv_positive(char **s, int fd, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
	{
		write(1, &s[fd][len], 1);
		len++;
	}
	if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		s[fd] = NULL;
	}
	else
	{
		*line = ft_substr(s[fd], 0, len);
		tmp = ft_strdup(&s[fd][len + 1]);
		free(s[fd]);
		s[fd] = tmp;
	}
	return (1);
}

int		decide_return_value(char **s, int rv, int fd, char **line)
{
	if (rv == 0 && s[fd] == NULL)
	{
		free(s[fd]);
		return (0);
	}
	else if (rv < 0)
		return (-1);
	else
		return (pattern_rv_positive(s, fd, line));
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*s[MAX_FD];
	char			*tmp;
	int				rv;

	if (fd < 0 || line == NULL || fd > MAX_FD)
		return (-1);
	while ((rv = read(fd, &buf, BUFFER_SIZE)) > 0)
	{
		buf[rv] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (decide_return_value(s, rv, fd, line));
}

//ファイル一個、読み込むのはできた。
//ファイルの内容によって例外処理しよう。
// 改行だけ -> 1、何にもなし-> 0、非表示もじ、
int main()
{
	int fd[4];
	char *line;

	printf("%zu\n",SIZE_MAX);
	fd[0] = open("text.txt",O_RDONLY);
	fd[1] = open("one.txt",O_RDONLY);
	fd[2] = open("two.txt",O_RDONLY);
	fd[3] = open("three.txt",O_RDONLY);
	ft_putstr_fd("-----------1週目----------\n",1);

	get_next_line(fd[0],&line);
	ft_putchar_fd('\n',1);


	get_next_line(fd[1],&line);
	ft_putchar_fd('\n',1);
	

	get_next_line(fd[2],&line);
	ft_putchar_fd('\n',1);

	get_next_line(fd[3],&line);
	ft_putchar_fd('\n',1);
	
	ft_putstr_fd("-----------2週目----------\n",1);
	get_next_line(fd[0],&line);
	ft_putchar_fd('\n',1);


	get_next_line(fd[1],&line);
	ft_putchar_fd('\n',1);
	

	get_next_line(fd[2],&line);
	ft_putchar_fd('\n',1);

	get_next_line(fd[3],&line);
	ft_putchar_fd('\n',1);
	// while(get_next_line(fd,&line))
	// {
	// 	ft_putstr_fd(line,fd);
	// }
	return (0);
}