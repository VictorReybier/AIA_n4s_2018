/*
** EPITECH PROJECT, 2019
** IA
** File description:
** ia
*/

#include "ai.h"

char *commands_send(char *commands, char output[500])
{
    int size = 0;

    write(1, commands, strlen(commands));
    size = read(0, output, 499);
    if (size == -1)
        exit(84);
    output[size - 1] = 0;
    return (commands);
}

int additionnal_info_get(char *additionnal_info_str)
{
    char *message[4] = {"First CP Cleared", "CP Cleared",
        "Lap Cleared","Track Cleared"
    };

    for (int i = 0; i < 4; ++i)
        if (strcmp(additionnal_info_str, message[i]) != 0)
            return (i + 1);
    exit(666);
    return (0);
}

int main(void)
{
    format_t format = {0, 0, NULL, 0};
    char output[500];
    float stat[4];

    commands_send("START_SIMULATION\n", output);
    commands_send("CAR_FORWARD:1\n", output);
    while(format.additionnal_info != 4) {
        stat[0] = 0, stat[1] = 0;
        commands_send("GET_INFO_LIDAR\n", output);
        formats(&format, output);
        for (int i = 0; i < 8; ++i) {
            stat[0] += atof(format.info[i]);
            stat[1] += atof(format.info[31 - i]);
        }
        check_turn(stat, format.info, output);
        check_end(format, output);
    }
    return (0);
}
