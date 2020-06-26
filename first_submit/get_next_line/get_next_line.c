/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwasa <yiwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:30:25 by yiwasa            #+#    #+#             */
/*   Updated: 2020/06/26 13:30:11 by yiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 100000000;

int get_next_line(int fd, char **line)
{
	char buf[100000000]; 
	while(!read(fd,&buf,1))
	{
		
	}
}


///とりあえず、一行ずつ読みこむようにしとくか
//baffaniitigyouzutuyomikomaseteriku
//難しいプログラムを描くときは、

int main()
{
	int fd;
	char *line;

	fd = open("text.txt",O_RDONLY);
	while(get_next_line(fd,&line))
	{
		printf("%s\n",line);
	}
	return (0);
}