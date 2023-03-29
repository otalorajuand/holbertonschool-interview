#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

   	if (head == NULL)
		return (NULL);

	current = *head;

    	new = malloc(sizeof(listint_t));
    	if (new == NULL)
        	return (NULL);

	new->n = number;

	if (*head == NULL)
        	*head = new;
    	else
    	{
        	while (current->next != NULL && current->next->n < number)
            		current = current->next;

	    	new->next = current->next;
		current->next = new;
	}

	return (new);
}
