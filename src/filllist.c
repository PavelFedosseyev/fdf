/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filllist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:52:38 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:44:29 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_str		*filllist(t_str *list, char *line)
{
	t_str	*tmp;
	t_str	*head;

	tmp = NULL;
	head = NULL;
	if (!list)
	{
		tmp = (t_str*)malloc(sizeof(t_str));
		tmp->str = ft_strdup(line);
		tmp->next = NULL;
		return (tmp);
	}
	head = list;
	tmp = (t_str*)malloc(sizeof(t_str));
	tmp->str = ft_strdup(line);
	tmp->next = NULL;
	while (head->next)
		head = head->next;
	head->next = tmp;
	return (list);
}

t_str		*openfile(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_str		*list;

	list = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR);
		if (fd == -1)
			error("Invalid file");
		while (get_next_line(fd, &line) == 1)
			{
				list = filllist(list, line);
				free (line);
			}
	}
	else
		error("Too many arguments");
	if (argc == 2)
		close(fd);
	return (list);
}
