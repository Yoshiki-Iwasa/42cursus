/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwasa <yiwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:30:25 by yiwasa            #+#    #+#             */
/*   Updated: 2020/06/27 17:57:55 by yiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//////これ、ファイルの中にヌルが入ってた場合はどうするんだろか。。。。。
//////mallocがおきて、その内容が破棄されるたびに、freeしないと

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *s;
	char *tmp;
	char *tmp2;
	int len;
	int rv;
	int i;

	if (fd < 0 || line == NULL)
		return (-1);
	while((rv = read(fd,&buf,BUFFER_SIZE)) > 0)
	{
		i++;
		buf[rv] = '\0';
		if(s == NULL)
			s = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s,buf);
			free(s);
			s = tmp;
		}
		if(ft_strchr(s,'\n'))
			break;	
	}
	if(rv == 0 && s == NULL)
	{
		free(s);
		return (0);
	}
	else if(rv < 0)
		return (-1);
	else
	{
		len = 0;
		while(s[len] != '\n' && s[len] != '\0')
		{
			write(1,&s[len],1);
			len++;
		}
		if(s[len] == '\0')
		{
			*line = ft_strdup(s);
			s = NULL;
		}
		else
		{	
			*line = ft_substr(s,0,len);
			tmp2 = ft_strdup(&s[len + 1]);
			free(s);
			s = tmp2;	
		}
		return (1);
	}	
}

//ファイル一個、読み込むのはできた。
//ファイルの内容によって例外処理しよう。
// 改行だけ -> 1、何にもなし-> 0、非表示もじ、
int main()
{
	int fd;
	char *line;
	char buf[BUFFER_SIZE];
	line = malloc(BUFFER_SIZE);
	fd = open("text.txt",O_RDONLY);	
	ft_putnbr_fd(get_next_line(fd,&line),1);
	while(get_next_line(fd,&line))
	{
		ft_putstr_fd(line,fd);
	}
	return (0);
}