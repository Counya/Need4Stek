/*
** EPITECH PROJECT, 2019
** turn_car.c
** File description:
** N4S
*/

#include "../include/n4s.h"

float calc_seuil(char **lidar)
{
    float   average = 0;

    for (int i = 3; i < 35; i += 1) {
        if (atof(lidar[i]) > 450) {
            return (450);
        }
        average += atof(lidar[i]);
    }
    return (average / 32);
}

float turn(char **lidar)
{
    int box = 3;
    float interval = 0;
    float max_interval = 0;
    int size_interval = 0;
    float seuil = calc_seuil(lidar);
    float direction = 0;

    while (box < 35) {
        while (box < 35 && atof(lidar[box]) >= seuil) {
            interval = interval + atof(lidar[box]);
            box = box + 1;
            size_interval = size_interval + 1; }
        if (interval > max_interval) {
            max_interval = interval;
            direction = box - (size_interval / 2.0); }
        box = box + 1;
        size_interval = 0;
        interval = 0;
    }
    return (((((direction-3) * 2.0) / 32.0) - 1.0) * -1.0);
}

void turn_car(char **lidar)
{
    float direction = turn(lidar);
    char *buffer = malloc(sizeof(char) * 10000);

    sprintf(buffer, "WHEELS_DIR:%f\n", direction);
    put_command(buffer);
}