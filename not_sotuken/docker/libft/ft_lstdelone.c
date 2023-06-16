/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:15:26 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/31 17:19:23 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del == 0 || lst == 0)
		return ;
	(*del)(lst->content);
	free(lst);
}
/* 
int main()
{
	t_list *new;
	t_list **lst;
	void (*del)(void*) = del;
	
	lst = (t_list **)malloc(sizeof(t_list*) * 6);
	lst[0] = ft_lstnew("0ban");
	lst[1] = ft_lstnew("1ban");
	lst[2] = ft_lstnew("2ban");
	lst[3] = ft_lstnew("3ban");
	lst[4] = ft_lstnew("4ban");
	lst[5] = 0;
	lst[0]->next = lst[1];
	lst[1]->next = lst[2];
	lst[2]->next = lst[3];
	lst[3]->next = lst[4];
	lst[4]->next = lst[5];
	ft_lstdelone(lst[0], del);

	t_list *now;
	now = lst[0];
	while(now != 0)
	{
		printf("now->content = %s\n", (char *)now->content);
		now = now->next;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == 0)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	del(void *content)
{
	content = 0;
	free(content);
}
 */