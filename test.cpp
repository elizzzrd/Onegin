#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"

int main()
{
    const char * filename = "onegintext.txt";
    size_t file_size = get_file_size(filename);

    printf("%lu\n", file_size);

    char * buffer = (char *) calloc(file_size + 1, sizeof(char)); 
    if (!buffer)
    {
        fprintf(stderr, "Memory allocation error");
        return -1;
    }

    size_t read_symbols = read_text_from_file(filename, file_size, buffer);
    printf("%lu\n", read_symbols);


    return 0;
}