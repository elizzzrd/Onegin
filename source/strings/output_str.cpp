#include <stdio.h>
#include "output_str.h"

void own_puts(const char *str)
{
    const char *elem = str;
    while (*elem != '\0')
    {
        putchar(*elem++);
    }
}

char * own_fgets(char * str, int n, FILE * stream)
{
    int ch;
    char *elem = str;

    while(--n > 0 && (ch = fgetc(stream)) != EOF)
    {
        if ((*elem++ = (char)ch) == '\n')
            break;
    }
    *elem = '\0';

    return (ch == EOF && elem == str) ? NULL: str;
}