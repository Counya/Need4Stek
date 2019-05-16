/*
** EPITECH PROJECT, 2019
** end_track.c
** File description:
** N4S
*/

#include <stdlib.h>
#include "../include/n4s.h"

int verif_float(char **lidar)
{
    int inde = 0;
    while (lidar[inde] != NULL) {
        inde++;
    }
    return (inde);
}

void end_track(char **lidar)
{
    if (verif_float(lidar) == 36) {
        if (strcmp(lidar[35], "Track Cleared") == 0) {
            put_command("car_forward:0.0\n");
            put_command("stop_simulation\n");
            exit(0);
        }
    }
    else if (strcmp(lidar[3], "Track Cleared") == 0) {
        put_command("car_forward:0.0\n");
        put_command("stop_simulation\n");
        exit(0);
    }
}