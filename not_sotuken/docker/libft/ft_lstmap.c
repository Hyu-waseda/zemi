/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:47:09 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/31 17:40:31 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (lst == 0 || f == 0 || del == 0)
		return (NULL);
	new_lst = 0;
	while (lst != 0)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == 0)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}

/* 
void *func(void *content);

void	del(void *content);

void *		lstmap_f(void *content) {
	(void)content;
	return ("OK !");
}

int main()
{
	t_list **lst;
	
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

	t_list *now;
	now = ft_lstmap(*lst, func, del);
	while(now != 0)
	{
		printf("now->content = %s\n", (char *)now->content);
		printf("new->next = %s\n", (char *)now->next);
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	new->next = 0;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	
	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	while (*lst != 0)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del == 0 || lst == 0)
		return ;
	(*del)(lst->content);
	free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void  *func(void *content)
{
	return ("OK");
}

void	del(void *content)
{
	content = 0;
	free(content);
}
 */