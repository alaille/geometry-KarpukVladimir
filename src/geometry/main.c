#include <stdio.h>
#include <string.h>
#include <libgeometry/functions.h>

int main()
{
    char str[100];

    int lines = check_line();

    FILE* file = fopen("input.txt", "r");
    for (int line = 0; line < lines; line++) {
        fgets(str, 100, file);
        str[strlen(str) - 1] = '\0';

        if (isCorrect(str)) {
            circle tr1; 
            tr1= getcircle(str);
            writePandS(tr1);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
} 