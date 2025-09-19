#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "allocation_str.h"

char * own_strdup(char * str)
{
    assert(str != NULL && "NULL pointer");
    char * allocated_str = (char *) calloc(strlen(str) + 1, sizeof(char));

    if (allocated_str != NULL)
    {
        strcpy(allocated_str, str);
    } 
    else
    {
        fprintf(stderr, "Allocation error");
    }

    return allocated_str;
}

size_t own_getline(char ** lineptr, size_t * n, FILE * stream) 
{
    if (stream == NULL) 
    {
        return (size_t)-1;
    }
    
    char * buffer = *lineptr;
    size_t size = *n;
    size_t len = 0;
    int ch;
    
    if (buffer == NULL || size == 0)
    {
        size = 2;  
        buffer = (char *)realloc(buffer, size);
        if (buffer == NULL) 
        {
            fprintf(stderr, "Allocation error");
            return (size_t)-1;
        }
        *lineptr = buffer;
        *n = size;
    }
    
    while ((ch = fgetc(stream)) != EOF) 
    {
        if (len + 1 >= size) 
        {
            size *= 2;
            buffer = (char *) realloc(*lineptr, size);
            if (buffer == NULL) 
            {
                fprintf(stderr, "Allocation error");
                return (size_t)-1;
            }
            *lineptr = buffer;
            *n = size;
        }

        buffer[len++] = (char)ch;
        if (ch == '\n') 
        {
            break;
        }
    }

    if (len == 0 && ch == EOF) 
    {
        return (size_t)-1;
    }

    buffer[len] = '\0';

    return len;
}
