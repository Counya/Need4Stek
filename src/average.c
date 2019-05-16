/*
** EPITECH PROJECT, 2019
** average
** File description:
** N4S
*/

#include "../include/n4s.h"

float average_left(char **lidar)
{
    float result = 0;
    int i = 3;

    while (i < 18) {
        result = result + atof(lidar[i]);
        i++;
    }
    return (result / 15);
}

float average_right(char **lidar)
{
    float result = 0;
    int e = 34;

    while (e > 19) {
        result = result + atof(lidar[e]);
        e--;
    }
    return (result / 15);
}

float average_mid(char **lidar)
{
    float result = atof(lidar[18]) + atof(lidar[19]);
    return (result / 2);
}