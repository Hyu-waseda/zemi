/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:40:07 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/25 17:58:27 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	new->next = 0;
}

/* 
int main()
{
	t_list *new;
	t_list **lst;
	
	new = ft_lstnew("new");
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
	ft_lstadd_back(lst, new);

	t_list *now;
	now = lst[0];
	while(now != 0)
	{
		printf("new->content = %s\n", (char *)now->content);
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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
 */