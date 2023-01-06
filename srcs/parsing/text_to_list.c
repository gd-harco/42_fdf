/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:23:46 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/15 16:26:57 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*put_file_in_list(int fd)
{
	t_list	*text_in_list;
	char	*buff;

	buff = get_next_line(fd);
	text_in_list = ft_lstnew((void *)buff);
	buff = get_next_line(fd);
	while (buff)
	{
		ft_lstadd_back(&text_in_list, ft_lstnew((void *)buff));
		buff = get_next_line(fd);
	}
	return (text_in_list);
}

t_list	*V_put_file_in_list(int fd)
{
	t_list	*text_in_list;
	t_list	*new_node;
	char	*buff;

	text_in_list = NULL;
	buff = get_next_line(fd);
	while (buff)
	{
		new_node = ft_lstnew((void *)buff);
		if (new_node == NULL)
			exit(1);
		ft_lstadd_back(&text_in_list, new_node);
		buff = get_next_line(fd);
	}
	return (text_in_list);
}
