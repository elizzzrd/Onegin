#pragma once
#include "read_file.h"

void print_strings_ptr(char * lines[MAX_LINES], int count);
void print_strings_square(char lines[MAX_LINES][MAX_LEN], int count);
void swap_lines_ptr(char * lines_ptr[], int index_1, int index_2);
void swap_lines_square(char lines[MAX_LINES][MAX_LEN], int index_1, int index_2);
void swap_lines_square_2(char lines[][MAX_LEN], int index_1, int index_2);
void direct_sort(char * ptr_massive[], int lines);
int reverse_compare_str(const void * string1, const void * string2);