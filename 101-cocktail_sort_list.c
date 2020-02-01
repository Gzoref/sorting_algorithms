#include "sort.h"
void swap_nodes(listint_t **list, listint_t **a, listint_t **b);
/**
 * cocktail_sort_list - sort doubly-linked list with cocktail method
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right = NULL, *curr, *temp;
	int dir = 1; /* forward = 1; reverse = -1 */

	/* cover NULL lists or list < 2 nodes */
	if (!list || !(*list) || !(*list)->next)
		return;

	curr = left = *list;
	while (left != right)
	{
		while (dir == 1)
		{
			if (curr->n > curr->next->n)
			{
				if (curr == *list)
					*list = curr->next;
				temp = curr->next;
				swap_nodes(list, &curr, &temp);
			}
			else
				curr = curr->next;

			if (curr->next == right)
			{
				dir = -1;
				right = curr;
				curr = curr->prev;
				break;
			}
		}
		while (dir == -1)
		{
			if (curr->n < curr->prev->n)
			{
				if (curr->prev == *list)
					*list = curr;
				if (curr->prev == left)
					left = curr;
				temp = curr->prev;
				swap_nodes(list, &temp, &curr);
			}
			else
				curr = curr->prev;

			if (curr == left)
			{
				dir = 1;
				left = curr->next;
				curr = curr->next->next;
				break;
			}
		}
	if (left->next == right || left->next->next == right)
		break;
	}
}
/**
 * swap_nodes - swap two nodes and print list
 * @list: list (for print)
 * @a: left node
 * @b: right node
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
	(*a)->next = (*b)->next;
	(*b)->prev = (*a)->prev;
	if ((*b)->next)
		(*b)->next->prev = (*a);
	if ((*a)->prev)
		(*a)->prev->next = (*b);
	(*b)->next = (*a);
	(*a)->prev = (*b);

	print_list(*list);
}
