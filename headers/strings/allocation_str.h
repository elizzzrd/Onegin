#pragma once
#include <stdlib.h>
#include <stdio.h>

char * own_strdup(char * str);
size_t own_getline(char ** lineptr, size_t * n, FILE * stream);