/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:33:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/15 15:01:30 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*struct_to_str(t_list **lst, int len, int *utils)
{
	int		i;
	char	*str;
	t_list	*tmp;

	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && *lst)
	{
		str[i] = *(char *)((*lst)->content);
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
		i++;
	}
	str[i] = '\0';
	return (utils[1] = 0, str);
}

char	*find_line_in_lst(t_list **lst, int *utils)
{
	t_list	*tmp;
	int		len;

	tmp = *lst;
	len = 0;
	while (tmp)
	{
		if (*(char *)(tmp->content) == '\n')
			return (struct_to_str(lst, len + 1, utils));
		else
		{
			tmp = tmp->next;
			len++;
		}
	}
	return (utils[1] = 0, NULL);
}

int	str_to_struct(char *str, t_list **lst)
{
	int		i;
	t_list	*new;

	i = 0;
	while (str[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (0);
		new->content = malloc(sizeof(char *));
		if (!new->content)
			return (free(new), 0);
		*(char *)(new->content) = str[i++];
		new->next = NULL;
		ft_lstadd_back(lst, new);
	}
	return (1);
}

char	*look_for_line(int fd, t_list **lst, char *buf, int *utils)
{
	utils[0] = read(fd, buf, BUFFER_SIZE);
	if (utils[0] < 0)
		return (NULL);
	buf[utils[0]] = '\0';
	if (!str_to_struct(buf, lst))
		return (NULL);
	return (find_line_in_lst(lst, utils));
}

/*
utils[0] = size_read;
utils[1] = is_error;
*/

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*buf;
	char			*str;
	int				utils[2];

	if (BUFFER_SIZE <= 0)
		return (free_lst(&lst), NULL);
	utils[1] = 1;
	utils[0] = BUFFER_SIZE;
	str = find_line_in_lst(&lst, utils);
	if (utils[1])
		return (free_lst(&lst), NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free_lst(&lst), NULL);
	while (!str && utils[0] > 0)
	{
		utils[1] = 1;
		str = look_for_line(fd, &lst, buf, utils);
		if (utils[1])
			return (free(buf), free_lst(&lst), NULL);
	}
	if (!utils[0] && lst)
		return (free(buf), struct_to_str(&lst, ft_lstsize(lst), utils));
	return (free(buf), str);
}


#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}

