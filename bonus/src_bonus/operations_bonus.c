/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:50 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 20:12:28 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	swap(t_list *stack, char c)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->head->content;
	stack->head->content = stack->head->next->content;
	stack->head->next->content = tmp;
	tmp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	swap_swap(t_list *a, t_list *b)
{
	swap(a, 's');
	swap(b, 's');
	write(1, "ss\n", 3);
}

void	push_ab(t_list *a, t_list *b)
{
	t_node	*node;

	node = create_node(b->tail->content);
	if (!node)
		return ;
	(*node).prev = a->tail;
	node->next = a->head;
	a->tail->next = node;
	a->head->prev = node;
	a->tail = node;
	a->size++;
	write(1, "pab\n", 4);
}

void	reverse_rotate(t_list *a, char c)
{
	if (!a || a->size <= 1)
		return ;
	a->head = a->tail;
	a->tail = a->tail->prev;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rotate(t_list *a, char c)
{
	if (!a || a->size <= 1)
		return ;
	a->tail = a->head;
	a->head = a->head->next;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}
