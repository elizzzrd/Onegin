#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "find_subelem.h"


const char * own_strstr(const char * string, const char * substring)
{
    assert(string != NULL && "NULL pointer");
    assert(substring != NULL && "NULL pointer");

    if (*substring == '\0')
    {
        return string;
    }

    for (const char * elem = string; *elem != '\0'; elem++)
    {
        if (*elem == *substring)
        {
            const char * temp_elem = elem;
            const char * temp_subelem = substring;

            while (*temp_elem != '\0' && *temp_subelem != '\0' && 
                    *temp_elem == *temp_subelem)
            {
                temp_elem++;
                temp_subelem++;
            }

            if (*temp_subelem == '\0')
            {
                return elem;
            }
        }
    }
    return NULL;
}

char * own_strtok(char * str, const char * delim) 
{
    assert(delim != NULL && "NULL pointer");

    static char * last_ptr = NULL; // статическая переменная для сохранения состояния функции между вызовами
    char * token_start = NULL; // начало нового токена (ненулевой символ, не встр в delim)

    if (str != NULL) // если строка новая - переустанавливаем last_ptr
    {
        last_ptr = str; 
    }
    if (last_ptr == NULL || *last_ptr == '\0') 
    {
        return NULL;
    }
    while (*last_ptr != '\0' && strchr(delim, *last_ptr) != NULL) // пропускаем первые разделители, после предыдущего вызова
    {
        last_ptr++;
    }
    if (*last_ptr == '\0') 
    {
        return NULL;
    }
    
    token_start = last_ptr; // запоминаем начало нового токена
    while (*last_ptr != '\0' && strchr(delim, *last_ptr) == NULL) // ищем конец токена
    {
        last_ptr++;
    }
    if (*last_ptr != '\0') // если нашли разделитель, заменяем его на нулевой символ
    {
        *last_ptr = '\0';
        last_ptr++;
    }
    
    return token_start;
}
