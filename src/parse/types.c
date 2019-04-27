/*
** EPITECH PROJECT, 2018
** json
** File description:
** types
*/

#include "../intern_json.h"

static bool ljson_is_end_delim(char c)
{
    return (c == '}' || c == ']' || c == ',');
}

static bool ljson_is_bool(char *raw, int idx)
{
    if (lstr_starts_with(raw + idx, "true") &&
        ljson_is_end_delim(raw[idx + 4]))
        return (true);
    if (lstr_starts_with(raw + idx, "false") &&
        ljson_is_end_delim(raw[idx + 5]))
        return (true);
    return (false);
}

static bool ljson_is_null(char *raw, int idx)
{
    return (lstr_starts_with(raw + idx, "null") &&
        ljson_is_end_delim(raw[idx + 4]));
}

json_type_t ljson_find_type(char *raw, int idx)
{
    json_type_tuple_t tab[4] = {{"{", JSON_OBJECT}, {"[", JSON_ARRAY},
        {"-0123456789.", JSON_NUMBER}, {"\"'", JSON_STRING}};
    int tabidx = -1;
    int cidx = -1;
    int len;

    tabidx = -1;
    while (++tabidx < 4) {
        len = strlen(tab[tabidx].chars);
        cidx = -1;
        while (++cidx < len)
            if (tab[tabidx].chars[cidx] == raw[idx])
                return (tab[tabidx].type);
    }
    if (ljson_is_bool(raw, idx))
        return (JSON_BOOL);
    else if (ljson_is_null(raw, idx))
        return (JSON_NULL);
    return (JSON_UNKNOWN);
}

int ljson_assign_value(char *raw, int idx, json_type_t type, void **data)
{
    int arr_idx = -1;
    json_parse_func_t func[6] = {{JSON_OBJECT, ljson_parse_object},
        {JSON_ARRAY, ljson_parse_array}, {JSON_NUMBER, ljson_parse_number},
        {JSON_STRING, ljson_parse_str}, {JSON_BOOL, ljson_parse_bool},
        {JSON_NULL, ljson_parse_null}};

    while (++arr_idx < 6)
        if (func[arr_idx].type == type)
            return (func[arr_idx].func(raw, idx, data));
    return (-1);
}