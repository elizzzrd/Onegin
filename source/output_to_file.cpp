#include <stdio.h>
#include <assert.h>
#include "read_file.h"
#include "std_str.h"
#include "output_to_file.h"
#include "text.h"


void write_one_poem_to_file(char * poem[], int lines, FILE * file)
{
    assert(poem);
    assert(lines > 0);

    for (int index = 0; index < lines; index++)
    { 
        size_t len = own_strlen(poem[index]);
        if (fwrite(poem[index], sizeof(char), len, file) != len)
        {
            fprintf(stderr, "Writing to file error\n");
            return;
        }
        fwrite("\n", sizeof(char), 1, file);
    }
    fwrite("\n", sizeof(char), 1, file); 
}


void output_to_file(text_t * text)
{
    assert(text);

    int lines = text -> lines_count;
    const char * filename = "text/poem.txt";
    FILE * file = fopen(filename, "a+");
    if (!file) 
    {
        fprintf(stderr, "Can not open the file %s.\n", filename);
        return;
    }

    fprintf(file, "Poem\n");
    write_one_poem_to_file(text -> original_lines, lines, file);

    fclose(file);
}

