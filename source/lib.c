/*
** EPITECH PROJECT, 2019
** IA
** File description:
** lib
*/

#include <string.h>
#include <stdlib.h>

int strcontent(char *str, char c)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == c)
            return (1);
    return (0);
}

int arraylen(char **array)
{
    int size = 0;

    while (array[size])
        ++size;
    return (size);
}

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i]; ++i)
        free(array[i]);
    free(array);
}

char *char_add_in_str(char *str, char add)
{
    int size = 0;

    if (str == NULL)
        str = malloc(sizeof(char) * 2);
    else {
        size = strlen(str);
        str = realloc(str, size + 2);
    }
    str[size] = add;
    str[++size] = 0;
    return (str);
}

char **str_to_word_array(char *str, char separator)
{
    char **array = NULL;
    int size = 1;
    int y = 0;

    for (int i = 0; str[i]; ++i)
        size += str[i] == separator;
    array = malloc(sizeof(char *) * ++size);
    array[y] = char_add_in_str(NULL, str[0]);
    for (int i = 1; str[i]; ++i) {
        if (str[i] == separator)
            array[++y] = char_add_in_str(NULL, str[++i]);
        else
            array[y] = char_add_in_str(array[y], str[i]);
    }
    array[++y] = NULL;
    return (array);
}