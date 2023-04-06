#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 180);
	if (!root)
	{
		printf("binary_tree_node returned NULL\n");
		return (1);
	}
	printf("Parent:%p\n", (void *)(root->parent));
	printf("Left:%p\n", (void *)(root->left));
	printf("Right:%p\n", (void *)(root->right));
	binary_tree_print(root);
	_binary_tree_delete(root);
	return (0);
}
