#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current, *temp;
    unsigned int position;

    if (*head == NULL)
    {
        return (-1);
    }

    current = *head;
    position = 0;

    while (position < index && current != NULL)
    {
        current = current->next;
        position++;
    }

    if (position != index)
    {
        return (-1);
    }

    if (index == 0)
    {
        temp = current->next;
        free(current);
        *head = temp;
        if (temp != NULL)
        {
            temp->prev = NULL;
        }
    }
    else
    {
        if (current->prev != NULL)
            current->prev->next = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;

        free(current);
    }

    return (1);
}