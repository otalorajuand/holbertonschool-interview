#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - reverses the second half of the linked list
 * @head: pointer to the head of the linked list
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * compare_lists - compares two linked lists for equality
 * @list1: pointer to the head of the first linked list
 * @list2: pointer to the head of the second linked list
 * Return: 1 if the lists are equal, 0 otherwise
 */
int compare_lists(listint_t *list1, listint_t *list2)
{
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->n != list2->n)
            return 0;
        list1 = list1->next;
        list2 = list2->next;
    }

    if (list1 == NULL && list2 == NULL)
        return 1;

    return 0;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow_ptr = *head;
    listint_t *fast_ptr = *head;
    listint_t *prev_slow_ptr = *head;
    listint_t *second_half;
    int palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return 1;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL)
    {
        second_half = slow_ptr->next;
    }
    else
    {
        second_half = slow_ptr;
    }

    prev_slow_ptr->next = NULL;
    second_half = reverse_list(second_half);
    palindrome = compare_lists(*head, second_half);
    second_half = reverse_list(second_half);

    if (fast_ptr != NULL)
    {
        prev_slow_ptr->next = slow_ptr;
        slow_ptr->next = second_half;
    }
    else
    {
        prev_slow_ptr->next = second_half;
    }

    return palindrome;
}

