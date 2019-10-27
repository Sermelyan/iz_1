/*
Copyright 2019 Сергей Меликян АПО-12
*/

#include "object.h"
#include <stdlib.h>
#include <string.h>

#define MAX_USR 50000000
#define MAX_OBJ 25000

Object* create_object(unsigned id) {
    Object* temp = calloc(1, sizeof(Object));;
    if (!temp || id >= MAX_OBJ) {
        free_object(temp);
        return NULL;
    }
    temp->obj_id = id;
    return temp;
}

void free_object(Object* object) {
    if (!object)
        return;
    if (object->rating_array)
        free(object->rating_array);
}

int add_rate(Object* obj, int m, unsigned user_id) {
    if (!obj || m == NOT_MARKED || user_id >= MAX_USR) {
        return 1;
    }
    unsigned size = obj->rate_size;
    unsigned pointer = obj->rate_ptr;
    Rate *array = obj->rating_array;

    if (!size) {
        size = 2;
        Rate *temp = calloc(size, sizeof(Rate));
        if (!temp) {
            return 1;
        }
        array = temp;
    }

    if (size == pointer) {
        size = size * 2;
        Rate *temp = realloc(array, size*sizeof(Rate));
        if (!temp) {
            return 1;
        }
        array = temp;
    }

    array[pointer].mark = m;
    array[pointer].user_id = user_id;

    obj->rate_ptr = pointer + 1;
    obj->rate_size = size;
    obj->rating_array = array;
    return 0;
}

Objects *create_objects(unsigned size) {
    if (size >= MAX_OBJ)
        return NULL;
    Objects* temp = calloc(1, sizeof(Objects));
    if (!temp)
        return NULL;
    temp->size = size;
    Object *t_arr = calloc(size, sizeof(Object));
    if (!t_arr) {
        free(temp);
        return NULL;
    }
    temp->array = t_arr;
    return temp;
}

void free_objects(Objects *objs) {
    unsigned size = objs->size;
    Object *arr = objs->array;
    for (unsigned i = 0; i < size; i++) {
        free_object(&arr[i]);
    }
    free(arr);
    free(objs);
}
