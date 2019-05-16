/*
** EPITECH PROJECT, 2019
** N4S
** File description:
** main.c
*/

#include "../include/n4s.h"

void engine(char **lidar)
{
    float gauche = average_left(lidar);
    float droite = average_right(lidar);
    float mid = average_mid(lidar);
    float result = gauche - droite;

    if (mid > 2000) {
        put_command("WHEELS_DIR:0.0\n");
        put_command("CAR_FORWARD:0.8\n");
    } else {
    speed_car(lidar);
    turn_car(lidar);
    }
}

char **put_command(char *command)
{
    char **lidar = malloc(sizeof(char *) * 300);
    char *line = NULL;
    size_t size;

    dprintf(1, command);
    getline(&line, &size, stdin);
    lidar = my_str_to_wordtab(line, ':');
    end_track(lidar);
    return lidar;
}

int main(void)
{
    char **lidar = NULL;

    put_command("start_simulation\n");
    while (1) {
        lidar = put_command("get_info_lidar\n");
        engine(lidar);
    }
}
