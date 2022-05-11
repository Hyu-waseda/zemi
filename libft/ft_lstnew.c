/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:25:50 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/25 17:59:15 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == 0)
		return (NULL);
	new->content = content;
	new->next = 0;
	return (new);
}
/* 
int main()
{
	t_list *new;
	
	new = ft_lstnew("new");
	printf("now->content = %s\n", (char *)new->content);
	printf("now->next = %s\n", (char *)new->next);
}
 */