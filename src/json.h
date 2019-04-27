/*
** EPITECH PROJECT, 2018
** json
** File description:
** json
*/

#pragma once

#include "hmap.h"
#include "str.h"
#include "vec.h"

typedef enum json_type_e {
    JSON_UNKNOWN,
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} json_type_t;

typedef struct json_item_s {
    json_type_t type;
    void *data;
} json_item_t;

typedef struct json_s {
    char *original;
    char *raw;
    json_item_t *root;
} json_t;

json_t *ljson_parse(char *text);
char *ljson_serialize(json_item_t *root);

json_item_t *ljson_item_new(json_type_t type, void *data);
void ljson_item_drop(json_item_t *item, bool free_payload);
