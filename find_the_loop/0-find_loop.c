#include "lists.h"

/**
 * find_listint_loop - Find the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head;
    listint_t *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;      /* Move one step at a time */
        fast = fast->next->next; /* Move two steps at a time */

        /* If there's a loop, slow and fast will eventually meet */
        if (slow == fast)
        {
            /* Move slow back to the head and advance both pointers at the same speed */
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; /* Return the node where the loop starts */
        }
    }

    return NULL; /* No loop found */
}
