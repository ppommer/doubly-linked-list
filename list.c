#include <stdlib.h>
#include <stdio.h>

#include "list.h"

list_t *list_init () {
    // Initialize list and allocate memory
    list_t *list = NULL;
    list = malloc(sizeof(list_t));

    // If no memory is left, return NULL
    if (list == NULL)
        return NULL;

    // Initialize list variables
    list->first = NULL;
    list->last = NULL;

    // Return address of the list
    return list;
}

struct list_elem *list_insert (list_t *list, char *data) {
    // Initialize list element and allocate memory
    struct list_elem *elem = NULL;
    elem = malloc(sizeof(struct list_elem));

    // If no memory is left, return NULL
    if (elem == NULL)
        return NULL;

    // Initialize elem variables
    elem->data = data;
    elem->next = list->first;
    list->first = elem;
    elem->prev = NULL;

    // Return address of elem
    return elem;
}

struct list_elem *list_append (list_t *list, char *data) {
    // Initialize list element and allocate memory
    struct list_elem *elem = NULL;
    elem = malloc(sizeof(struct list_elem));

    // If no memory is left, return NULL
    if (elem == NULL)
        return NULL;

    // Initialize elem variables
    elem->data = data;
    elem->next = NULL;
    elem->prev = list->last;
    list->last = elem;

    // Return address of elem
    return elem;
}

int list_remove (list_t *list, struct list_elem *elem) {
    // If list is empty, return -1
    if (list == NULL || list->first == NULL || list->last == NULL)
        return -1;
    // If elem is the first element in the list
    if (elem == list->first) {
        list->first = elem->next;
        list->first->prev = NULL;
        free(elem);
        return 0;
    }
    // If elem is the last element in the list
    if (elem == list->last) {
        list->last = elem->prev;
        list->last->next = NULL;
        free(elem);
        return 0;
    }

    // If elem is between first and last element in the list
    // Initialize temporary list element to search the list
    struct list_elem *temp = NULL;
    temp = list->first;

    // Search list to from first to last to find the element to be deleted
    while (temp != NULL) {
        // If the element is found ...
        if (temp == elem) {
           elem->prev->next = elem->next;
           elem->next->prev = elem->prev;
           free(elem);
           return 0;
        }
        // Iterate
        temp = temp->next;
    }
    // Return -1 if element was not found
    return -1;
}

void list_finit (list_t *list) {
    // Initialize temporary list element to search the list
    struct list_elem *temp = NULL;
    temp = list->first;

    // Iterate through list from first to last and delete selected elements
    while (temp != NULL) {
        list_remove(list, temp);
        temp = temp->next;
    }
}

void list_print (list_t *list, void (*print_elem) (char *)) {
    int ctr = 1;

    // Initialize temporary list element to iterate through the list
    struct list_elem *temp = NULL;
    if (list != NULL && list->first != NULL && list->last != NULL)
        temp = list->first;

    // Print data of list elements
    while (temp != NULL) {
        printf("%d", ctr++);
        print_elem(temp->data);
        temp = temp->next;
    }
}

struct list_elem *list_find (list_t *list, char *data, int (*cmp_elem) (const char *, const char *)) {
    // Initialize temporary list element pointer to iterate through the list
    struct list_elem *temp = NULL;
    if (list != NULL && list->first != NULL && list->last != NULL)
        temp = list->first;

    // Return element if found
    while (temp != NULL) {
        if (cmp_elem(data, temp->data) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
