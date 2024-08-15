/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:43:47 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 11:44:08 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	is_new_max(int value, t_data **b)
{
	t_data	*curr;

	curr = *b;
	while (curr)
	{
		if (value < curr->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

size_t	is_new_min(int value, t_data **b)
{
	t_data	*curr;

	curr = *b;
	while (curr)
	{
		if (value > curr->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

size_t	calc_max_b_index(t_data *b)
{
	int	max;
	size_t	j;
	size_t	i;

	max = b->content;
	j = 1;
	i = 1;
	while (b)
	{
		if (b->content > max)
		{
			max = b->content;
			i = j;
		}
		b = b->next;
		++j;
	}
	return (i);	
}

size_t	calc_cost(t_data **a, t_data **b, int a_index)
{
	size_t	max_b_index;
	size_t	i;
	size_t	cost;
	size_t	len_b;
	size_t	len_a;

	max_b_index = calc_max_b_index(*b);
	i = -1;
	cost = 0;
	len_b = count_list(*b);
	if (max_b_index <= (size_t)(len_b / 2))
	{
		while (++i < max_b_index - 1)
			cost++;
	}
	else
	{
		while (++i < (size_t)len_b - max_b_index + 1)
			cost++;
	}
	i = -1;
	len_a = count_list(*a);
	if (a_index <= len_a / 2)
	{
		while (++i < (size_t)(a_index - 1))
			cost++;
	}
	else
	{
		while (++i < (size_t)(len_a - a_index + 1))
			cost++;
	}
	return (cost + 1);
}

void	catch_cost(t_data **a, t_data **b)
{
	t_data	*curr;
	int	value;
	int	a_index;

	curr = *a;
	a_index = 1;
	while (curr)
	{
		value = curr->content;
		if (is_new_max(value, b) || is_new_min(value, b))
			curr->cost = calc_cost(a, b, a_index);
		curr = curr->next;
		++a_index;
	}
}

void	print_cost(t_data **a)
{
	t_data *curr;
	
	curr = *a;
	while (curr)
	{
		printf("%d: %d\n", curr->content, curr->cost);
		curr = curr->next;
	}
}

void	sort(t_data **a, t_data **b)
{
	int	stack_len;

	push(b, a, "pb");
	push(b, a, "pb");
	stack_len = count_list(*a);	
	while (stack_len != 3)
	{
		catch_cost(a, b);
		print_cost(a);
		break ;
		--stack_len;
	}
	sort_three(a);
}

