/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:59:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/22 14:52:45 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_list	*put_file_in_list(int fd);
static void		get_vmap(t_list *list, t_vector_map *v_map);
static size_t	get_nb_word(char *vstr);

t_vector_map	parsing(char *filename)
{
	int				fd;
	t_list			*file_in_list;
	t_vector_map	vector_map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (1);
	}
	file_in_list = put_file_in_list(fd);
	close(fd);
	get_vmap(file_in_list, &vector_map);
	ft_lstclear(&file_in_list, free);
	return (vector_map);
}

static t_list	*put_file_in_list(int fd)
{
	t_list	*list;
	t_list	*new_node;
	char	*buff;

	list = NULL;
	buff = get_next_line(fd);
	while (buff)
	{
		new_node = ft_lstnew(buff);
		if (new_node == NULL)
		{
			ft_lstclear(&list, &free);
			exit(1);
		}
		ft_lstadd_back(&list, new_node);
		buff = get_next_line(fd);
	}
	return (list);
}

static void	get_vmap(t_list *list, t_vector_map *v_map)
{
	size_t	line_index;

	if (list == NULL)
		exit(1);
	v_map->height = ft_lstsize(list);
	v_map->width = get_nb_word(list->content);
	v_map->map = malloc(sizeof (t_vector3d *) * v_map->height);
	v_map->map_to_draw = malloc(sizeof (t_vector3d *) * v_map->height);
	if (v_map->map == NULL)
		exit(1);
	line_index = -1;
	while (++line_index < v_map->height)
		v_map->map[line_index] = create_line((int) line_index, list);
}

static size_t	get_nb_word(char *str)
{
	size_t	nb_word;
	size_t	i;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			nb_word++;
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i])
			i++;
	}
	return (nb_word);
}
