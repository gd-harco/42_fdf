/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:59:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 14:14:45 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		free_int_map(t_int_map int_map);
static t_list	*put_file_in_list(int fd);
static void		get_int_map(t_list *list, t_int_map *int_map,
					t_vector_map *v_map);
static size_t	get_nb_word(char *vstr);

t_vector_map	parsing(char *filename)
{
	int				fd;
	t_list			*file_in_list;
	t_int_map		int_map;
	t_vector_map	vector_map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (1);
	}
	file_in_list = put_file_in_list(fd);
	get_int_map(file_in_list, &int_map, &vector_map);
	ft_lstclear(&file_in_list, free);
	int_map_to_v_map(&int_map, &vector_map);
	free_int_map(int_map);
	return (vector_map);
}

static void	free_int_map(t_int_map int_map)
{
	size_t	i;

	i = 0;
	while (i < int_map.height)
	{
		free(int_map.map[i]);
		i++;
	}
	free(int_map.map);
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

static void	get_int_map(t_list *list, t_int_map *int_map, t_vector_map *v_map)
{
	size_t	i;

	if (list == NULL)
		exit(1);
	int_map->height = ft_lstsize(list);
	int_map->width = get_nb_word(list->content);
	v_map->height = int_map->height;
	v_map->width = int_map->width;
	int_map->map = malloc(sizeof (int *) * int_map->height);
	v_map->map = malloc(sizeof (t_vector3d *) * int_map->height);
	if (int_map->map == NULL || v_map->map == NULL)
		exit(1);
	i = -1;
	while (++i < int_map->height)
		int_map->map[i] = create_int_line((int) i, list);
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
