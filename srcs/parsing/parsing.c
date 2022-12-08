/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/08 22:44:01 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include <fcntl.h>

void	table(int fd)
{
	char	*temp;
	char	*final;

	final = "";
	temp = get_next_line(fd);
	while (temp)
	{
		final = ft_strjoin(final, temp);
		temp = get_next_line(fd);
	}
	ft_printf("%s", final);
	free(temp);
	free(final);
}

int main(int argc, char const *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	table(fd);
	return 0;
}

