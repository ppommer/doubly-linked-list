#include <stdio.h>
#include "list.c"

int main(int argc, char** argv) {
    list_t *list = list_init();
    list_append(list, "ist");
    list_append(list, "Paul");
    list_append(list, "Pommer");
    list_insert(list, "Das");
    list_print(list, (void (*)(char *)) printf);
    return 0;
}
