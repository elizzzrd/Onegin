#pragma once
#define MAX_LINES 6000 


size_t get_file_size(const char * filename);
size_t read_text_from_file(const char * filename, size_t size, char * buffer);
int set_ptr_massive(char * buffer, char * ptr_massive[], int max_lines);
