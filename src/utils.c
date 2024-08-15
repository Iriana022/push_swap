/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:44:47 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 11:45:11 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_data(t_data *data)
{
	for (t_data *curr = data; curr != NULL; curr = curr->next)
		printf("%d ", curr->content);
	printf("\n");
}

t_data	*find_last(t_data *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

size_t	count_list(t_data *stack)
{
	size_t	counter;

	counter = 0;
	while (stack)
	{
		++counter;
		stack = stack->next;
	}
	return (counter);
}

size_t	is_sorted(t_data *stack)
{
	t_data	*curr;
	t_data	*tmp;

	curr = stack;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (curr->content > tmp->content)
				return (0);
			tmp = tmp->next;
		}			
		curr = curr->next;
	}
	return (1);
}
