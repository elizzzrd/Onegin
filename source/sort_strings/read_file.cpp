#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "allocation_str.h"
#include "read_file.h"
#include <sys/stat.h>
 

void free_lines(char * lines[], int count) 
{
    for (int i = 0; i < count; i++) 
    {
        free(lines[i]);
    }
}

int read_to_ptr_massive(const char * filename, char * ptr_massive[MAX_LEN], int max_lines, int max_len)
{
    assert(filename != NULL && "NULL pointer");

    FILE * file = fopen(filename, "r");
    if (!file) 
    {
        fprintf(stderr, "Can not open the file %s.\n", filename);
        return 0;
    }

    int count = 0;
    char * buffer = NULL;
    size_t len = 0;
    size_t read = 0;

    for (count = 0; count < max_lines && (read = own_getline(&buffer, &len, file)) != (size_t)-1; count++)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        char * elem = buffer;
        while (*elem != '\0' && isspace((unsigned char)(*elem))) 
        {
            elem++;
        }

        ptr_massive[count] = own_strdup(elem);
        if (!ptr_massive[count])
        {
            fprintf(stderr, "Strdup failed\n");
            free(buffer);
            fclose(file);
            return 0;
        }
    }

    free(buffer);
    fclose(file);
    return count;
}

size_t get_file_size(const char * filename) 
{
    assert(filename != NULL);
    
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) 
    {
        return -1;
    }

    return (file_stat.st_size);
}

size_t read_text_from_file(const char * filename, int size, char * buffer)
{
    assert(filename != NULL);
    assert(size > 0 && size < MAX_LEN * MAX_LINES);

    FILE * file = fopen(filename, "r");
    if (!file) 
    {
        fprintf(stderr, "Can not open the file %s.\n", filename);
        return -1;
    }

    size_t read_symbols = fread(buffer, sizeof(char), size, file);
    buffer[size] = '\0';

    return read_symbols;
}

int set_ptr_massive(char * buffer, char * ptr_massive[MAX_LEN], int max_lines)
{
    int count = 0;
    char * token = strtok(buffer, "\n");
    while (count < max_lines && token != NULL) 
    {
        ptr_massive[count] = token;
        token = strtok(NULL, "\n");
        count++;
    }
    return count;
}

void output_to_file(char * sorted_lines[], char * reverse_sorted_lines[], char * lines_ptr[], int size, int lines)
{
    assert(sorted_lines != NULL);
    assert(reverse_sorted_lines != NULL);
    assert(lines_ptr != NULL);
    assert(size > 0 || size < MAX_LEN * MAX_LINES);
    assert(lines < 0 || lines < MAX_LINES);

    const char * filename = "poem.txt";
    FILE * file = fopen(filename, "w");
    if (!file) 
    {
        fprintf(stderr, "Can not open the file %s.\n", filename);
        return;
    }

    fprintf(file, "Direct sorting poem\n");
    write_one_poem_to_file(sorted_lines, lines, file);
   
    fprintf(file, "Reverse sorting poem\n");
    write_one_poem_to_file(reverse_sorted_lines, lines, file);

    fprintf(file, "Original poem\n");
    write_one_poem_to_file(lines_ptr, lines, file);

    fclose(file);
}

void write_one_poem_to_file(char * poem[], int lines, FILE * file)
{
    for (int index = 0; index < lines; index++)
    { 
        size_t len = strlen(poem[index]);
        if (fwrite(poem[index], sizeof(char), len, file) != len)
        {
            fprintf(stderr, "Writing to file error\n");
        }
        fwrite("\n", sizeof(char), 1, file);
    }
    fwrite("\n", sizeof(char), 1, file); 
}