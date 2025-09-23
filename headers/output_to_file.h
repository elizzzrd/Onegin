#pragma once
#include <stdio.h>

void output_to_file(char * sorted_lines[], char * reverse_sorted_lines[], char * lines_ptr[], int lines);
void write_one_poem_to_file(char * poem[], int lines, FILE * file);