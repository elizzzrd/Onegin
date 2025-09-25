#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "read_file.h"
#include "allocation_str.h"
#include "operate_lines.h"


void print_strings_ptr(char * lines[MAX_LINES], int count)
{
    assert(lines != NULL);
    
    printf("\nRead %d lines:\n", count);
    for (int i = 0; i < count; i++) 
    {
        printf("[%d] %s\n", i + 1, lines[i]);
    }
}


void swap_lines_ptr(char * lines_ptr[], int index_1, int index_2)
{
    assert(lines_ptr != NULL);
    
    if (index_1 < 0 || index_1 > MAX_LINES ||
        index_2 < 0 || index_2 > MAX_LINES)
    {
        puts("Invalid strings indexes fo swap");
        return;
    }
    else if (index_1 == index_2)
    {
        puts("Can not swap equal strings");
        return;
    }

    char * temp = lines_ptr[index_1];
    lines_ptr[index_1] = lines_ptr[index_2];
    lines_ptr[index_2] = temp;
}


void free_lines(char ** lines, int count) 
{
    assert(lines);
    assert(count > 0);

    if (lines == NULL) return;

    for (int i = 0; i < count; i++) 
    {
        if (lines[i] != NULL) free(lines[i]);
    }
    free(lines);
}


char ** inizialize_massive(int lines_count)
{
    assert(lines_count != 0);

    char ** massive = (char**)calloc((size_t)lines_count, sizeof(char*));
    if (massive == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    return massive;
}


char * inizialize_buffer(size_t file_size)
{
    assert(file_size > 0);

    if (file_size == 0)
    {
        fprintf(stderr, "File size is 0\n");
        file_size = 1;
    }

    char * buffer = (char *)calloc(file_size + 1, sizeof(char));
    if (buffer == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    return buffer;
}


int copy_lines_to_massive(char ** dest_massive, char ** source_massive, int lines_count)
{
    for (int i = 0; i < lines_count; i++) 
    {
        dest_massive[i] = own_strdup(source_massive[i]);
        if (dest_massive[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed for string %d\n", i);
            for (int j = 0; j < i; j++)
            {
                free(dest_massive[j]);
            }
            free(dest_massive);
            return 0;
        }
    }
    return 1;
}


