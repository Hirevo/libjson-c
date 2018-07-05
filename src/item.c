/*
** EPITECH PROJECT, 2018
** json
** File description:
** item
*/

#include "json.h"

json_item_t *ljson_item_new(json_type_t type, void *data)
{
	json_item_t *item = calloc(1, sizeof(json_item_t));

	if (item == 0)
		return (0);
	item->type = type;
	item->data = data;
	return (item);
}

void ljson_item_drop(json_item_t *item, bool free_payload)
{
	if (free_payload)
		free(item->data);
	free(item);
}
