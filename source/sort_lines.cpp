#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <allocation_str.h>
#include "std_str.h"
#include "find_subelem.h"
#include "read_file.h"
#include "sort_lines.h"
#include "operate_lines.h"


void direct_sort(char * ptr_massive[], int lines) // bubble sort version
{   
    for (int i = 0; i < lines; i++) 
    {
        int flag = 0;
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

int direct_compare_str(const void * string1,
                    const void * string2)
{
    const char * s1 = *(const char **)string1;
    const char * s2 = *(const char **)string2;

   int res = own_strcmp(s1, s2);
   return res;
}


int reverse_compare_str(const void * string1,
                const void * string2)
{
    const char * s1 = *(const char **)string1;
    const char * s2 = *(const char **)string2;

    int i = (int)own_strlen(s1) - 1;
    int j = (int)own_strlen(s2) - 1;

    while (i >= 0 && j >= 0) 
    {
        while (i >= 0 && !isalpha((unsigned char) s1[i])) i--;
        while (j >= 0 && !isalpha((unsigned char) s2[j])) j--;

        if (i < 0 || j < 0) break;

        char c1 = (char)toupper(s1[i]);
        char c2 = (char)toupper(s2[j]);

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








