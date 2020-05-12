#include "list.h"

list_t *list_init () {
    //TODO
}

struct list_elem *list_insert (list_t *list, char *data) {
    //TODO
}

struct list_elem *list_append (list_t *list, char *data) {
    //TODO
}

int list_remove (list_t *list, struct list_elem *elem) {
    //TODO
}

void list_finit (list_t *list) {
    //TODO
}

void list_print (list_t *list, void (*print_elem) (char *)) {
    //TODO
}

struct list_elem *list_find (list_t *list, char *data, int (*cmp_elem) (const char *, const char *)) {
    //TODO
}
