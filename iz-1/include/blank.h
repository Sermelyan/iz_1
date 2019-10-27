//
// Created by ser on 10.10.2019.
//

#ifndef IZ_1_INCLUDE_BLANK_H_
#define IZ_1_INCLUDE_BLANK_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

#define MAXSTR 256
#define check_and_print(out, str)\
        if (in == stdin) {\
            printf("%s", str);\
        }

typedef struct blank_struct {
    unsigned long number;
    char storage_place[MAXSTR];
    char responsible_name[MAXSTR];
    char responsible_surname[MAXSTR];
} Blank;

Blank* new_blank(void);
int check_string(const char *str);
int check_blank(Blank *blank);
void get_string(FILE *in, char *str);
Blank* get_blank(FILE *in, FILE *out);
void print_blank(FILE *out, Blank *bl);

#endif  //  IZ_1_INCLUDE_BLANK_H_
