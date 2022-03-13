#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

char* skipCircle(char* cursor, char* startcursor, char circle[])
{
    int len = 0;

    while (*startcursor == ' ') {
        startcursor++;
        cursor++;
    }

    while (isalpha(*cursor) != 0) {
        len++;
        cursor++;
    }

    if ((strncmp(circle, startcursor, strlen(circle)) == 0)
        && (len == strlen(circle))) {
        return cursor;
    }

    return NULL;
}

char* skipSign(char* cursor, char sign)
{
    while (*cursor != sign) {
        if (*cursor == ' ') {
            cursor++;
        }

        return NULL;
    }

    if (*cursor == sign) {
        cursor++;
    }

    return cursor;
}

char* skipDigit(char* cursor, double* digit)
{
    char* d;

    while (isdigit(*cursor) == 0) {
        if (*cursor == ' ') {
            cursor++;
        } else {
            return NULL;
        }
    }

    if (isdigit(*cursor) != 0) {
        *digit = strtod(cursor, &d);
        cursor = d;
    }

    return cursor;
}

char* checkEndStr(char* cursor)
{
    while (*cursor != '\n') {
        if (*cursor == ' ') {
            cursor++;
        }
        return NULL;
    }

    return cursor;
}

int main()
{
    char str[SIZE];
    char* cursor = str;
    char* startcursor = str;
    char circle[] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};
    double x, y, radius;

    fgets(str, SIZE, stdin);

    if ((cursor = skipCircle(cursor, startcursor, circle)) == NULL) {
        printf("The name of the figure is entered incorrectly: expected "
               "'circle'\n");
        return -1;
    }

    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("The character is entered incorrectly: expected '('\n");
        return -2;
    }

    if ((cursor = skipDigit(cursor, &x)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -3;
    }

    if ((cursor = skipDigit(cursor, &y)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -4;
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        return -5;
    }

    if ((cursor = skipDigit(cursor, &radius)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -6;
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("The character is entered incorrectly: expected ')'\n");
        return -7;
    }

    if ((cursor = checkEndStr(cursor)) == NULL) {
        printf("An unexpected token at the end of a line\n");
        return -8;
    }

    printf("\nFigure name: %s\n", circle);
    printf("x = %.1lf\n", x);
    printf("y = %.1lf\n", y);
    printf("radius = %.1lf\n", radius);

    return 0;
}