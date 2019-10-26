/*
Copyright 2019 Сергей Меликян АПО-12
*/

#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

#include "user.h"
#include "object.h"

Users* gen_users(unsigned size);
Objects* gen_objects(unsigned size);
int make_random_rate(Users *u, Objects *o, unsigned count, unsigned max_thr);

// void print_users(const Users *u);
// void print_objects(const Objects *o);

#endif  //  INCLUDE_UTILS_H_
