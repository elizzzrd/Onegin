#include <stdio.h>
#include <assert.h>
#include "read_file.h"
#include "std_str.h"
#include "output_to_file.h"


void write_one_poem_to_file(char * poem[], int lines, FILE * file)
{
    for (int index = 0; index < lines; index++)
    { 
        size_t len = own_strlen(poem[index]);
        if (fwrite(poem[index], sizeof(char), len, file) != len)
        {
            fprintf(stderr, "Writing to file error\n");
        }
        fwrite("\n", sizeof(char), 1, file);
    }
    fwrite("\n", sizeof(char), 1, file); 
}


void output_to_file(char * sorted_lines[], char * reverse_sorted_lines[], char * lines_ptr[], int lines)
{
    assert(sorted_lines != NULL);
    assert(reverse_sorted_lines != NULL);
    assert(lines_ptr != NULL);
    assert(lines < 0 || lines < MAX_LINES);

    const char * filename = "text/poem.txt";
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

