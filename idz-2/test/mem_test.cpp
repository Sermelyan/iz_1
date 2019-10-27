
extern "C" {
    #include "top_single.h"
    #include "utils.h"
}
#include <dlfcn.h>
#include <stdlib.h>

int main() {
    Users *users = gen_users(5000);
    if (!users) {
        return 1;
    }
    Objects *objects = gen_objects(160);
    if (!objects) {
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
        return 1;
    }
    get_top_multi = (Top* (*)(const Objects*, const User*, unsigned int)) dlsym(library, "get_top");


    Top *top = get_top(objects, &(users->array[0]), 10);


    Top* top_multi = (*get_top_multi) (objects, &(users->array[0]), 10);

    free(top);
    free(top_multi);

    free_users(users);
    free_objects(objects);
    dlclose(library);
    return 0;
}