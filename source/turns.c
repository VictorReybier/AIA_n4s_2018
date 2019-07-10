/*
** EPITECH PROJECT, 2019
** turns.c
** File description:
** wall detection
*/

#include "ai.h"

void turn(float turn_val, char output[500])
{
    int size = 0;

    dprintf(1, "WHEELS_DIR:%f\n", turn_val);
    size = read(0, output, 499);
    if (size == -1)
        exit(84);
    output[size - 1] = 0;
}

void long_turn(float *stat, char **info, char output[500])
{
    if (stat[0] < stat[1] && atof(info[0]) < 600)
        turn(-0.3, output);
    else if (stat[0] > stat[1] && atof(info[31]) < 600)
        turn(0.3, output);
    else
        turn(0, output);
}

void short_turn(float *stat, char **info, char output[500])
{
    if (atof(info[0]) < 330) {
        commands_send("CAR_FORWARD:0.15\n", output);
        turn(-0.5, output);
    }
    if (atof(info[31]) < 330) {
        commands_send("CAR_FORWARD:0.15\n", output);
        turn(0.5, output);
    }
    if (atof(info[0]) < 170) {
        commands_send("CAR_FORWARD:0.02\n", output);
        turn(-1, output);
    }
    if (atof(info[31]) < 170) {
        commands_send("CAR_FORWARD:0.02\n", output);
        turn(1, output);
    }
    if (atof(info[0]) > 250 && atof(info[31]) > 250) {
        commands_send("CAR_FORWARD:0.3\n", output);
        turn(0, output);
    }
}

void backwards(float *stat, char **info, char output[500])
{
    commands_send("CAR_BACKWARDS:0.2\n", output);
    if (atof(info[0]) < 100)
        turn(0.4, output);
    else
        turn(-0.4, output);
}

void check_turn(float *stat, char **info, char output[500])
{
    if (atof(info[0]) < 100 || atof(info[31]) < 100)
        backwards(stat, info, output);
    else {
        long_turn(stat, info, output);
        short_turn(stat, info, output);
    }
}
