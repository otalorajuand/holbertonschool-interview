#include <stdlib.h>
#include "list.h"
#include <string.h>

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: The list to modify
 * @str: The string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *new_node = malloc(sizeof(List));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return (NULL);
    }

    if (*list == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        *list = new_node;
    }
    else
    {
        List *last = (*list)->prev;
        new_node->prev = last;
        new_node->next = *list;
        last->next = new_node;
        (*list)->prev = new_node;
    }

    return (new_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular linked list
 * @list: The list to modify
 * @str: The string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node = malloc(sizeof(List));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return (NULL);
    }

    if (*list == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        *list = new_node;
    }
    else
    {
        List *first = *list;
        List *last = first->prev;

        new_node->prev = last;
        new_node->next = first;
        last->next = new_node;
        first->prev = new_node;
        *list = new_node;
    }

    return (new_node);
}
