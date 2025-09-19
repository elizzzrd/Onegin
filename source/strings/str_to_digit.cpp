#include <ctype.h>
#include "str_to_digit.h"


int own_atoi(const char *str)
{
    int digit = 0, count = 0;
    int sign = 0;

    for (count = 0; isspace(str[count]); count++)
    {
        ;
    }

    if (str[count] == '+' || str[count] == '-')
    {
        sign = (str[count] == '-') ? -1: 1;
        count++;
    }

    for (digit = 0; isdigit(str[count]); count++)
    {
        digit = 10 * digit + (str[count] - '0');
    }
    return sign * digit;
}

double own_atof(const char *str)
{
    double digit = 0, power = 0;
    int count = 0, sign = 0;

    for (count = 0; isspace(str[count]); count++)
    {
        ;
    }
    
    if (str[count] == '+' || str[count] == '-')
    {
        sign = (str[count] == '-') ? -1: 1;
        count++;
    }
    
    for (digit = 0.0; isdigit(str[count]); count++)
    {
        digit = 10.0 * digit + (str[count] - '0');
    }

    if (str[count] == '.')
        count++;

    for (power = 1.0; isdigit(str[count]); count++)
    {
        digit = 10.0 * digit + (str[count] - '0');
        power *= 10.0;
    }
    return sign * digit / power;
}