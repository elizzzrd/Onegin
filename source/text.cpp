#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort_lines.h"
#include "text.h"
#include "operate_lines.h"


int create_text(const char * filename, text_t * text) 
{
    assert(filename);
    assert(text);

    text -> filename = filename;

    char ** original_lines = inizialize_massive(MAX_LINES);
    if (original_lines == NULL) return 0;
    text -> original_lines = original_lines;
    
    size_t file_size = get_file_size(filename);
    text -> file_size = file_size;

    char * buffer = inizialize_buffer(file_size);
    if (buffer == NULL) return 0;

    size_t read_symbols = read_text_from_file(filename, file_size, buffer);
    if (read_symbols <= file_size) 
    {
        buffer[read_symbols] = '\0'; 
    } 
    else 
    {
        buffer[file_size] = '\0'; 
    }
    text -> buffer = buffer;

    int lines_count = set_ptr_massive(buffer, original_lines, MAX_LINES);
    text -> lines_count = lines_count;
    
    return 1;
}


void sort_text(text_t * text, comparator_t comparator)
{
    assert(text);

    qsort(text -> original_lines, (size_t)text -> lines_count, sizeof(char *), comparator);
    return;
}


void clean_all(char ** sorted_lines, char ** reverse_sorted_lines, text_t * text)
{
    assert(text);

    free(text -> original_lines);
    free(text -> buffer);
    free_lines(reverse_sorted_lines, text -> lines_count);
    free_lines(sorted_lines, text -> lines_count);
}