#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <allocation_str.h>
#include "std_str.h"
#include "find_subelem.h"
#include "read_file.h"

void print_strings_ptr(char * lines[MAX_LINES], int count)
{
    assert(lines != NULL);
    printf("\nRead %d lines:\n", count);
    for (int i = 0; i < count; i++) 
    {
        printf("[%d] %s\n", i + 1, lines[i]);
    }
}

void swap_lines_ptr(char * lines_ptr[], int index_1, int index_2)
{
    assert(lines_ptr != NULL);
    if (index_1 < 0 || index_1 > MAX_LINES ||
        index_2 < 0 || index_2 > MAX_LINES)
    {
        puts("Invalid strings indexes fo swap");
        return;
    }
    else if (index_1 == index_2)
    {
        puts("Can not swap equal strings");
        return;
    }

    char * temp = lines_ptr[index_1];
    lines_ptr[index_1] = lines_ptr[index_2];
    lines_ptr[index_2] = temp;
}

void print_strings_square(char lines[MAX_LINES][MAX_LEN], int count)
{
    assert(lines != NULL);
    printf("\nRead %d lines:\n", count);
    for (int i = 0; i < count; i++) 
    {
        printf("[%d] %s\n", i + 1, lines[i]);
    }
}

void swap_lines_square(char lines[MAX_LINES][MAX_LEN], int index_1, int index_2)
{
    assert(lines != NULL);
    if (index_1 == index_2 || index_1 < 0 || index_1 > MAX_LINES ||
                              index_2 < 0 || index_2 > MAX_LINES)
    {
        puts("Invalid strings indexes fo swap");
        return;
    }
    else if (index_1 == index_2)
    {
        puts("Can not swap equal strings");
        return;
    }

    char temp[MAX_LEN]= {};
    memcpy(temp, lines[index_1], MAX_LEN);
    memcpy(lines[index_1], lines[index_2], MAX_LEN);
    memcpy(lines[index_2], temp, MAX_LEN);
}

void swap_lines_square_2(char lines[][MAX_LEN], int index_1, int index_2) 
{
    assert(lines != NULL);
    if (index_1 == index_2 || index_1 < 0 || index_1 > MAX_LINES ||
                              index_2 < 0 || index_2 > MAX_LINES)
    {
        printf("Invalid strings indexes fo swap");
        return;
    }
    else if (index_1 == index_2)
    {
        puts("Can not swap equal strings");
        return;
    }

    int max_len = (strlen(lines[index_1]) > strlen(lines[index_2])) 
                  ? strlen(lines[index_1]) : strlen(lines[index_2]);

    for (int k = 0; k <= max_len; k++) 
    {
        char tmp = lines[index_1][k];
        lines[index_1][k] = lines[index_2][k];
        lines[index_2][k] = tmp;
    }
}


void direct_sort(char * ptr_massive[], int lines) // bubble sort version
{   
    for (int i = 0; i < lines; i++) 
    {
        bool flag = false;
        for (int j = 0; j < lines - 1 - i; j++)
        {
            if (own_strcmp(ptr_massive[j], ptr_massive[j + 1]) > 0) 
            {
                swap_lines_ptr(ptr_massive, j, j + 1);
                flag = true;
            } 
        }
        if (!flag)
            break;
    }
}


int reverse_compare_str(const void * string1,
                const void * string2)
{
    const char * s1 = *(const char **)string1;
    const char * s2 = *(const char **)string2;

    int i = strlen(s1) - 1;
    int j = strlen(s2) - 1;

    while (i >= 0 && j >= 0) 
    {
        while (i >= 0 && !isalpha((unsigned char) s1[i])) i--;
        while (j >= 0 && !isalpha((unsigned char) s2[j])) j--;

        if (i < 0 || j < 0) break;

        char c1 = toupper((unsigned char)s1[i]);
        char c2 = toupper((unsigned char)s2[j]);

        if (c1 != c2)
        {
            if (c1 < c2) return -1;
            if (c1 > c2) return 1;
        }
        else 
        {
            i--;
            j--;
        } 
    }

    if (i < 0 && j < 0) return 0; // equal
    if (i < 0) return -1;  // str1 < str2
    return 1; // str1 > str2
}








