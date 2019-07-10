/*
** EPITECH PROJECT, 2019
** format.c
** File description:
** all format
*/

#include "ai.h"

char **format_4(format_t *format, char **output)
{
    free_array(output);
}

char **format_3(format_t *format, char **output)
{
    free_array(output);
}

void format_2(format_t *format, char **output)
{
    format->info = malloc(sizeof(char *) * 33);
    for (int i = 3; i < 35; ++i)
        format->info[i - 3] = output[i];
    free(*output);
    free(output[1]);
    free(output[2]);
    free(output[35]);
    free(output);
}

void format_common(format_t *format, char **output)
{
    int len = arraylen(output);

    format->value_id = atoi(*output);
    format->status = (strcmp(output[1], "KO") != 0);
    format->additionnal_info = additionnal_info_get(output[len - 1]);
}

void formats(format_t *format, char output[500])
{
    char **output_tab = str_to_word_array(output, ':');

    format_common(format, output_tab);
    switch (arraylen(output_tab)) {
    case 36:
        format_2(format, output_tab);
        break;
    case 5:
        if (strcontent(output_tab[3], ','))
            format_4(format, output_tab);
        else
            format_3(format, output_tab);
        break;
    default:
        free_array(output_tab);
    }
}
