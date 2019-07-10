/*
** EPITECH PROJECT, 2019
** IA
** File description:
** ai
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#ifndef AI_H_
#define AI_H_

typedef struct format {
    int value_id;
    int status;
    char **info;
    int additionnal_info;
} format_t;

int arraylen(char **array);
void free_array(char **array);
int strcontent(char *str, char c);
char **str_to_word_array(char *str, char separator);
void formats(format_t *format, char output[500]);
char *commands_send(char *commands, char output[500]);
int additionnal_info_get(char *additionnal_info_str);
int check_end(format_t format, char output[500]);
void check_turn(float *stat, char **info, char output[500]);

#endif
