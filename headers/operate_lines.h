#pragma once

void print_strings_ptr(char * lines[], int count);
void swap_lines_ptr(char * lines_ptr[], int index_1, int index_2);
void free_lines(char * lines[], int count);
char ** inizialize_massive(int lines_count);
char * inizialize_buffer(size_t file_size);
int copy_lines_to_massive(char ** dest_massive, char ** source_massive, int lines_count);
