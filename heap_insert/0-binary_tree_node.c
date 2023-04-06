#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_node - creates a binary tree node
 *
 * @value: The value of the new node. 
 * @parent: Pointer to the parent node
 * Return: A pointer to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;

	return (new);
}

