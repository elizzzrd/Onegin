#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"
#include "sort_lines.h"
#include "operate_lines.h"
#include "output_to_file.h"



int main() 
{
    char ** original_lines = inizialize_massive(MAX_LINES);
    if (original_lines == NULL) return 1;

    const char * filename = "text/oneginfull.txt";
    size_t file_size = get_file_size(filename);

    char * buffer = inizialize_buffer(file_size);
    if (buffer == NULL) return 1;

    size_t read_symbols = read_text_from_file(filename, file_size, buffer);
    if (read_symbols <= file_size) 
    {
    buffer[read_symbols] = '\0'; 
    } 
    else 
    {
    buffer[file_size] = '\0'; 
    }

    int lines_count = set_ptr_massive(buffer, original_lines, MAX_LINES);


    char ** sorted_lines = inizialize_massive(lines_count);
    if (sorted_lines == NULL) return 1;
    if (!copy_lines_to_massive(sorted_lines, original_lines, lines_count)) return 1;
    direct_sort(sorted_lines, lines_count);


    char ** reverse_sorted_lines = inizialize_massive(lines_count);
    if (reverse_sorted_lines == NULL) return 1;
    if (!copy_lines_to_massive(reverse_sorted_lines, original_lines, lines_count)) return 1;
    qsort(reverse_sorted_lines, (size_t)lines_count, sizeof(char *), reverse_compare_str);


    output_to_file(sorted_lines, reverse_sorted_lines, original_lines, lines_count);
    clean_all_massives(original_lines, buffer, sorted_lines, reverse_sorted_lines, lines_count);
    printf("Programm is finished!!!!\n");

    return 0;
}

