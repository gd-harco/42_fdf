/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_chained.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:23:46 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/14 14:09:34 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*put_file_in_list(int fd)
{
	t_list			*text_in_list;
	char			*buff;

	text_in_list = NULL;
	buff = get_next_line(fd);
	ft_lstadd_back(&text_in_list, ft_lstnew((void *)buff));
	// text_in_list->content = (void *)buff;
	// text_in_list->next = NULL;
	// free(buff);
	buff = get_next_line(fd);
	while (buff)
	{
		ft_lstadd_back(&text_in_list, ft_lstnew((void *)buff));
		// free (buff);
		buff = get_next_line(fd);
	}
	return (text_in_list);
}
