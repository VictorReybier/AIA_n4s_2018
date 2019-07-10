/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** end.c
*/

#include "ai.h"

int check_end(format_t format, char output[500])
{
    if (format.additionnal_info == 4) {
        commands_send("CAR_FORWARD:0\n", output);
        commands_send("STOP_SIMULATION\n", output);
        exit (0);
    }
}
