#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "std_str.h"


char * own_strchr(const char * str, int c)
{
    const char *elem = str;
    while (*elem != '\0')
    {
        if (*elem == c)
        {
            return (char*)elem;
        }
        else
        {
            elem++;
        }
    }
    return NULL;
}

size_t own_strlen(const char * str)
{
    size_t count = 0;
    const char * elem = str;
    while (*elem != '\0')
    {
        count++;
        elem++;
    }
    return count;
}

char * own_strcpy(char * destination, const char * source)
{
    size_t count = 0;
    while (source[count] != '\0')
    {
        destination[count] = source[count];
        count++;
    }
    destination[count] = '\0';
    return destination;
}

char * own_strncpy(char * destination, const char * source, size_t size)
{
    size_t count = 0;
    while (source[count] != '\0' && count < size)
    {
        destination[count] = source[count];
        count++;
    }
    destination[count] = '\0';
    return destination;
}

char * own_strcat(char * destination, const char * source)
{
    size_t len = strlen(destination);
    for (int i = 0; source[i] != '\0'; i++)
    {
        destination[len + i] = source[i];
    }
    destination[len + strlen(source)] = '\0';
    return (char *)destination;
}

char * own_strncat(char * destination, const char * source, size_t n)
{
    size_t len = strlen(destination);
    for (size_t i = 0; source[i] != '\0' && i < n; i++)
    {
        destination[len + i] = source[i];
    }
    destination[len + n] = '\0';
    return (char *)destination;
}

int own_strcmp(const char * s1, const char * s2) 
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    while (*s1 != '\0' && !isalpha((unsigned char)(*s1))) 
    {
        s1++;
    }
    while (*s2 != '\0' && !isalpha((unsigned char)(*s2))) 
    {
        s2++;
    }

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char * str1 = (char *) calloc(len1, sizeof(char));
    char * str2 = (char *) calloc(len2, sizeof(char));

    to_upper_str(s1, str1);
    to_upper_str(s2, str2);

    while (*str1 && (*str1 == *str2)) 
    {
        str1++;
        str2++;
    }

    return (unsigned char)*str1 - (unsigned char)*str2;
}

void to_upper_str(const char * input, char * output)
{
    int i = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        output[i] = toupper((unsigned char)input[i]);
    }
    output[i] = '\0';
}