/*
** EPITECH PROJECT, 2019
** n4S
** File description:
** header
*/


#ifndef header
#define header

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **my_str_to_wordtab(char *str, char limit);
float average_left(char **lidar);
float average_right(char **lidar);
float average_mid(char **lidar);
void end_track(char **lidar);
void turn_car(char **lidar);
void speed_car(char **lidar);
char **put_command(char *command);

#endif /* !header */
