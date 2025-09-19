#pragma once

#define MAX_LINES 10000   
#define MAX_LEN   256  

int read_to_ptr_massive(const char * filename, char * ptr_massive[MAX_LEN], int max_lines, int max_len);
void free_lines(char * lines[], int count);
size_t get_file_size(const char * filename);
size_t read_text_from_file(const char * filename, int size, char * buffer);
int set_ptr_massive(char * buffer, char * ptr_massive[MAX_LEN], int max_lines);
void output_to_file(char * sorted_lines[], char * reverse_sorted_lines[], char * lines_ptr[], int size, int lines);
void write_one_poem_to_file(char * poem[], int lines, FILE * file);