#pragma once
#include <stdlib.h>

char * own_strchr(const char *str, int c);
size_t own_strlen(const char *str);
char * own_strcpy(char *destination, const char *source);
char * own_strncpy(char * destination, const char *source, size_t size);
char * own_strcat(char * destination, const char * source);
char * own_strncat(char * destination, const char * source, size_t n);
int own_strcmp(const char * s1, const char * s2);
void to_upper_str(const char * input, char * output);