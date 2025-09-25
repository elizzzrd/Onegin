#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "allocation_str.h"
#include "read_file.h"
#include "find_subelem.h"
#include <sys/stat.h>
 

size_t get_file_size(const char * filename) 
{
    assert(filename != NULL);
    
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) 
    {
        return (size_t)-1;
    }

    return (size_t)(file_stat.st_size);
}


size_t read_text_from_file(const char * filename, size_t size, char * buffer)
{
    assert(filename != NULL);
    assert(size > 0);

    FILE * file = fopen(filename, "r");
    if (!file) 
    {
        fprintf(stderr, "Can not open the file %s.\n", filename);
        return (size_t)-1;
    }

    size_t read_symbols = fread(buffer, sizeof(char), size, file);
    buffer[size] = '\0';

    return read_symbols;
}


int set_ptr_massive(char * buffer, char * ptr_massive[], int max_lines)
{
    assert(buffer);
    assert(ptr_massive);

    int count = 0;
    char * token = own_strtok(buffer, "\n");
    while (count < max_lines && token != NULL) 
    {
        ptr_massive[count] = token;
        token = own_strtok(NULL, "\n");
        count++;
    }
    return count;
}
