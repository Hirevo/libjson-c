/*
** EPITECH PROJECT, 2018
** json
** File description:
** is
*/

#include "intern_json.h"

bool ljson_is_space(char c)
{
	return ((c == ' ') || (c == '\n') || (c == '\t'));
}

int ljson_is_comment(char *str, int idx)
{
	if (strncmp(str + idx, "//", 2) == 0)
		return (0);
	if (strncmp(str + idx, "/*", 2) == 0)
		return (1);
	return (-1);
}
