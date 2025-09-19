#include <stdio.h>
#include <string.h>
#include "allocation_str.h"
#include "read_file.h"
#include "fun_lines.h"

char lines_square[MAX_LINES][MAX_LEN]= {};
char * lines_ptr[MAX_LINES] = {};


int main() 
{
    const char * filename = "onegin.txt";
    size_t file_size = get_file_size(filename);

    char * buffer = (char *) calloc(file_size + 1, sizeof(char)); 
    if (!buffer)
    {
        fprintf(stderr, "Memory allocation error");
        return -1;
    }

    size_t read_symbols = read_text_from_file(filename, file_size, buffer);
    buffer[read_symbols] = '\0';

    int lines_count = set_ptr_massive(buffer, lines_ptr, MAX_LINES);
    // printf("\nOriginal text:\n");
    // print_strings_ptr(lines_ptr, lines_count);


    char * sorted_lines[lines_count] = {};
    for (int i = 0; i < lines_count; i++) 
    {
        sorted_lines[i] = own_strdup(lines_ptr[i]);
    }
    direct_sort(sorted_lines, lines_count);
    // printf("\nSorted strings:\n");
    // print_strings_ptr(sorted_lines, lines_count);


    char * reverse_sorted_lines[lines_count] = {};
    for (int i = 0; i < lines_count; i++) 
    {
        reverse_sorted_lines[i] = own_strdup(lines_ptr[i]);
    }
    qsort(reverse_sorted_lines, lines_count, sizeof(char *), reverse_compare_str);
    // printf("\nSorted strings_2:\n");
    // print_strings_ptr(reverse_sorted_lines, lines_count);


    output_to_file(sorted_lines, reverse_sorted_lines, lines_ptr, file_size, lines_count);
    free_lines(sorted_lines, lines_count);
    free_lines(reverse_sorted_lines, lines_count);
    free(buffer);
    return 0;
}




// int count = 0;
// if (!(count = read_to_ptr_massive(filename, lines_ptr, MAX_LINES, MAX_LEN)))
// {
//     return 1;
// }
// puts("Read in ptr massive");
// print_strings_ptr(lines_ptr, count);
// for (int index = 0; index < count; index++)
// {
//     strcpy(lines_square[index], lines_ptr[index]);
// }
// free_lines(lines_ptr, count);