#pragma once
#include <stdio.h>
#include "text.h"

void output_to_file( text_t * text);
void write_one_poem_to_file(char * poem[], int lines, FILE * file);