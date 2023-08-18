#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Computes the size of a heap
 * @root: Pointer to the root node of the heap
 * Return: Size of the heap
 */
size_t heap_size(heap_t *root)
{
    if (root == NULL)
        return 0;
    return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * heapify_down - Restore the heap property by moving the value down
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left != NULL && left->n > largest->n)
        largest = left;
    if (right != NULL && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        int tmp = root->n;
        root->n = largest->n;
        largest->n = tmp;
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
    if (*root == NULL)
        return 0;

    int extracted_value;
    extracted_value = (*root)->n;

    heap_t *last_node = *root;
    while (last_node->right != NULL)
    {
        if (last_node->right != NULL)
        {
            if (last_node->right->left != NULL || last_node->right->right != NULL)
                last_node = last_node->right;
            else
                last_node = last_node->left;
        }
        else
        {
            last_node = last_node->left;
        }
    }

    (*root)->n = last_node->n;

    if (last_node->parent->right != NULL)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);

    heapify_down(*root);

    return extracted_value;
}
