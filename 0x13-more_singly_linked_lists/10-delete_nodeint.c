#include "lists.h"
#include <stdlib.h>
/**
 * delete_nodeint_at_index - Deletes the node at a given position in the list.
 * @head: A pointer to the address of the head of the list.
 * @index: The index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;
	prev = NULL;

	while (temp != NULL && i < index)
	{
		prev = temp;
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (-1);

	if (prev == NULL)
		*head = temp->next;
	else
		prev->next = temp->next;

	free(temp);
	return (1);
}
