/*
Copyright 2019 Сергей Меликян АПО-12
*/

#ifndef IDZ_2_INCLUDE_UTILS_H_
#define IDZ_2_INCLUDE_UTILS_H_

#include "user.h"
#include "object.h"

Users* gen_users(unsigned size);
Objects* gen_objects(unsigned size);
int make_random_rate(Users *u, Objects *o, unsigned count, unsigned max_thr);

// void print_users(const Users *u);
// void print_objects(const Objects *o);

#endif  //  IDZ_2_INCLUDE_UTILS_H_
