/*
** EPITECH PROJECT, 2018
** json
** File description:
** base
*/

#include "../intern_json.h"
#include <stdio.h>

int ljson_serialize_bool(json_item_t *elem, char **output)
{
    char *arr[2] = {"false", "true"};

    *output = lstr_append(*output, arr[(long)elem->data]);
    if (*output == NULL)
        return (-1);
    return (0);
}

int ljson_serialize_null(json_item_t *elem, char **output)
{
    (void)elem;
    *output = lstr_append(*output, "null");
    if (*output == NULL)
        return (-1);
    return (0);
}

int ljson_serialize_number(json_item_t *elem, char **output)
{
    double value = (*((double *)&elem->data));
    int size = snprintf(0, 0, "%g", value);
    char *str = 0;

    if (size == -1)
        return (-1);
    str = calloc(size + 1, sizeof(char));
    if (str == 0 || snprintf(str, size + 1, "%g", value) == -1)
        return (-1);
    *output = lstr_append(*output, str);
    free(str);
    if (*output == NULL)
        return (-1);
    return (0);
}

int ljson_serialize_str(json_item_t *elem, char **output)
{
    *output = lstr_concat(
        *output, 3, LSTR_STR, "\"", LSTR_STR, elem->data, LSTR_STR, "\"");
    if (*output == NULL)
        return (-1);
    return (0);
}

int ljson_serialize_elem(json_item_t *elem, char **output)
{
    json_serialize_func_t branches[6] = {{JSON_OBJECT, ljson_serialize_object},
        {JSON_ARRAY, ljson_serialize_array},
        {JSON_NUMBER, ljson_serialize_number},
        {JSON_STRING, ljson_serialize_str}, {JSON_BOOL, ljson_serialize_bool},
        {JSON_NULL, ljson_serialize_null}};

    for (size_t idx = 0; idx < 6; idx++)
        if (elem->type == branches[idx].type)
            return (branches[idx].func(elem, output));
    return (-1);
}
