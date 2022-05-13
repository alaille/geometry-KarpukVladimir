#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

typedef struct {
    double x;
    double y;
    double r;
} circle;

int check_line();
int isCorrect(char* str);
circle getcircle(char* str);
void writePandS(circle tr1);

#endif //  _FUNCTIONS_H_