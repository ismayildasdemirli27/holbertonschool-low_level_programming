#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: data for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* Əgər indeks 0-dırsa, birbaşa əvvələ əlavə edən funksiyanı çağırırıq */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* İndeksdən bir əvvəlki (idx - 1) düyünü tapırıq */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* Əgər temp NULL oldusa, deməli indeks siyahının limitini aşıb */
	if (temp == NULL)
		return (NULL);

	/* Əgər temp sonuncu düyündürsə, birbaşa sona əlavə edən funksiyanı çağırırıq */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Ortaya əlavə etmək üçün yaddaş ayırırıq */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
