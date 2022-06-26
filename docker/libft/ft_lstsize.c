/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:25:03 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/22 16:06:53 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst != 0)
	{
		lst_size++;
		lst = lst->next;
	}
	return (lst_size);
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

	printf("%d\n", ft_lstsize(lst[0]));
	printf("%d\n", ft_lstsize(NULL));
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
 */