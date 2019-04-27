/*
** EPITECH PROJECT, 2018
** json
** File description:
** list
*/

#include "../intern_json.h"

int ljson_parse_array(char *raw, int idx, void **data)
{
    json_type_t type;
    void *tmp;
    bool hasNext = (raw[idx + 1] && raw[idx + 1] != ']');

    *((vec_t **)data) = lvec_new();
    idx += 1;
    while (hasNext) {
        if (raw[idx] != ',') {
            type = ljson_find_type(raw, idx);
            if (type == JSON_UNKNOWN)
                return (-1);
            idx = ljson_assign_value(raw, idx, type, &tmp);
            if (idx == -1)
                return (-1);
        }
        lvec_push_back(*((vec_t **)data), 1, ljson_item_new(type, tmp));
        hasNext = (raw[idx] == ',');
        idx += !!hasNext;
    }
    return ((raw[idx] != ']') ? -1 : (idx + 1));
}
