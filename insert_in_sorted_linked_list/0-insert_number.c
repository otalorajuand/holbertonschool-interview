#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

   	if (*head == NULL || head == NULL)
	{
		return (NULL);
	}

	current = *head;

    	new = malloc(sizeof(listint_t));
    	if (new == NULL)
        	return (NULL);

	while (current->next->n < number && current->next != NULL)
	{
		current = current->next;
	}

    	new->n = number;
    	new->next = current->next;
	current->next = new;

	return (new);
}
