/*
** EPITECH PROJECT, 2019
** N4S
** File description:
** my_str_to_wordtab
*/

#include <stdio.h>
#include <stdlib.h>

int words(char *str, char limit)
{
    int count = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] == limit)
            count++;
        i++;
    }
    return (count);
}

char *wordcpy(char *src, char *dest, int bgn, int end)
{
    int i = 0;

    while (bgn != end) {
        dest[i] = src[bgn];
        i++;
        bgn++;
    }
    return (dest);
}

char **fill_word_array(char *str, char **wordtab, int spaces, char limit)
{
    int bgn = 0;
    int i = 0;
    int j = 0;

    while (j < spaces) {
        while (str[i] != limit && str[i]) {
            i++;
        }
        if ((wordtab[j] = malloc(sizeof(char) * (i - bgn) + 1)) == NULL) {
            return (NULL);
        }
        wordcpy(str, wordtab[j], bgn, i);
        i++;
        bgn = i;
        j++;
    }
    return (wordtab);
}

char **my_str_to_wordtab(char *str, char limit)
{
    int i = 0;
    int nb_words = words(str, limit) + 1;
    char **wordtab = NULL;

    wordtab = malloc(sizeof(char *) * nb_words + 1);
    fill_word_array(str, wordtab, nb_words, limit);
    return (wordtab);
}