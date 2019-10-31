/*
Copyright 2019 Сергей Меликян АПО-12
*/

#include "utils.h"
#include "top_single.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    Users *users = gen_users(5000);
    if (!users) {
        perror("Cant get Users");
        return 1;
    }
    Objects *objects = gen_objects(160);
    if (!objects) {
        perror("Cant get Objects\n");
        free_users(users);
        return 1;
    }
    unsigned thr = 2;
    if (make_random_rate(users, objects, 500000, thr)) {
        free_users(users);
        free_objects(objects);
        return 1;
    }

    void *library;
    Top* (*get_top_multi)(const Objects *o, const User *u, unsigned c);
    library = dlopen("./libtop_multi.so", RTLD_LAZY);
    if (!library) {
        perror("Cant open lib libtop_multi.so\n");
        return 1;
    }
    get_top_multi = dlsym(library, "get_top");
    if (dlerror() != NULL) {
        perror("Cant find function in library\n");
        return 1;
    }

    Top *top = get_top(objects, &(users->array[0]), 10);
    if (!top) {
        perror("Error on single get_top\n");
    }

    Top *top_multi = (*get_top_multi) (objects, &(users->array[0]), 10);
    if (!top_multi) {
        perror("Error on multi get_top\n");
    }

    free(top);
    free(top_multi);
    free_users(users);
    free_objects(objects);
    dlclose(library);
    return 0;
}
