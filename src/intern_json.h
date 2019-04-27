/*
** EPITECH PROJECT, 2018
** json
** File description:
** libjson
*/

#pragma once

#include "json.h"

#define COMMENT_REPLACE                                                       \
    if (lstr_starts_with(str + adv, tab[type][tabidx])) {                     \
        len += strlen(tab[type][tabidx]);                                     \
        return (ljson_remove_substr(str, idx, len));                          \
    }

typedef struct json_parse_func_s {
    json_type_t type;
    int (*func)(char *, int, void **);
} json_parse_func_t;

typedef struct json_serialize_func_s {
    json_type_t type;
    int (*func)(json_item_t *, char **);
} json_serialize_func_t;

typedef struct json_type_tuple_s {
    char *chars;
    json_type_t type;
} json_type_tuple_t;

/*
** Preprocessing
*/
char *ljson_normalize(char *str);
bool ljson_is_space(char c);
int ljson_is_comment(char *str, int idx);
char *ljson_remove_comment(char *str, int idx, int type);
char *ljson_pack(char *str);
char *ljson_clear(char *str);
int ljson_space_len(char *str, int idx);
char *ljson_remove_substr(char *str, int idx, int len);

/*
** Parsing
*/
json_item_t *ljson_build_tree(char *raw);
json_type_t ljson_find_type(char *raw, int idx);
int ljson_assign_value(char *raw, int idx, json_type_t type, void **data);
int ljson_parse_elem(char *raw, int idx, hmap_t *root);
int ljson_parse_str(char *raw, int idx, void **data);
int ljson_parse_number(char *raw, int idx, void **data);
int ljson_parse_object(char *raw, int idx, void **data);
int ljson_parse_array(char *raw, int idx, void **data);
int ljson_parse_bool(char *raw, int idx, void **data);
int ljson_parse_null(char *raw, int idx, void **data);

/*
** Serializing
*/
int ljson_serialize_elem(json_item_t *elem, char **output);
int ljson_serialize_str(json_item_t *elem, char **output);
int ljson_serialize_number(json_item_t *elem, char **output);
int ljson_serialize_object(json_item_t *elem, char **output);
int ljson_serialize_array(json_item_t *elem, char **output);
int ljson_serialize_bool(json_item_t *elem, char **output);
int ljson_serialize_null(json_item_t *elem, char **output);
