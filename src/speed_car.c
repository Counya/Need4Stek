/*
** EPITECH PROJECT, 2019
** speed_car.c
** File description:
** N4S
*/

#include "../include/n4s.h"

void speed_car(char **lidar)
{
    float mid = average_mid(lidar);
    float vitesse = (1.0 * (mid - 100)) / 3010.0;
    char *buffer = malloc(sizeof(char) * 10000);

    vitesse = vitesse < 1 ? vitesse : 1;
    vitesse = vitesse > 0 ? vitesse : 0;
    sprintf(buffer, "car_forward:%f\n", vitesse);
    put_command(buffer);
}