#pragma once
#include <stdio.h>

typedef struct 
{
    const char * filename;
    size_t file_size;
    char * buffer;
    char ** original_lines;
    int lines_count;
} text_t;

typedef int (*comparator_t)(const void*, const void*);

int create_text(const char * filename, text_t * text);
char ** sort_text(text_t * text, comparator_t comparator);
void clean_all(char ** sorted_lines, char ** reverse_sorted_lines, text_t * text);