#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"
#include "sort_lines.h"
#include "operate_lines.h"
#include "output_to_file.h"
#include "text.h"


int main() 
{
    const char * filename = "text/onegin.txt";
    text_t text = {};

    if (!create_text(filename, &text))
    {
        fprintf(stderr, "Creating text error\n");
        return 1;
    }    

    sort_text(&text, direct_compare_str);
    output_to_file(&text);

    sort_text(&text, reverse_compare_str);
    output_to_file(&text);

    //clean_all(sorted_lines, reverse_sorted_lines, &text);
    free(text.original_lines);
    free(text.buffer);

    printf("Programm is finished!!!!\n");

    return 0;
}

