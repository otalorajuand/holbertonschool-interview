#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (create_avl_tree(array, 0, size - 1, NULL));
}

/**
 * create_avl_tree - Recursively creates an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *create_avl_tree(int *array, int start, int end, avl_t *parent)
{
    int mid;
    avl_t *root;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    root = malloc(sizeof(avl_t));
    if (root == NULL)
        return (NULL);

    root->n = array[mid];
    root->parent = parent;
    root->left = create_avl_tree(array, start, mid - 1, root);
    root->right = create_avl_tree(array, mid + 1, end, root);

    return (root);
}
