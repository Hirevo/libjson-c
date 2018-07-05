/*
** EPITECH PROJECT, 2018
** json
** File description:
** object
*/

#include "../intern_json.h"

static int internal_ljson_serialize_object_helper(
	char **output, int idx, vec_t *keys, vec_t *values)
{
	if (idx) {
		*output = lstr_append(*output, ",");
		if (*output == NULL)
			return (-1);
	}
	else {
		*output = lstr_append(*output, "");
		if (*output == NULL)
			return (-1);
	}
	*output = lstr_concat(*output, 3, LSTR_CHAR, '"', LSTR_STR,
		keys->arr[idx], LSTR_STR, "\":");
	if (*output == NULL ||
		ljson_serialize_elem(values->arr[idx], output) == -1)
		return (-1);
	return (0);
}

int ljson_serialize_object(json_item_t *elem, char **output)
{
	vec_t *keys = ((hmap_t *)elem->data)->key_table;
	vec_t *values = ((hmap_t *)elem->data)->value_table;
	size_t size = ((hmap_t *)elem->data)->size;

	*output = lstr_append(*output, "{");
	if (*output == NULL)
		return (-1);
	for (size_t idx = 0; idx < size; idx++)
		if (internal_ljson_serialize_object_helper(
			    output, idx, keys, values) == -1)
			return (-1);
	*output = lstr_append(*output, "}");
	if (*output == NULL)
		return (-1);
	return (0);
}

static int internal_ljson_serialize_array_helper(
	char **output, int idx, json_item_t *elem)
{
	if (idx) {
		*output = lstr_append(*output, ",");
		if (*output == NULL)
			return (-1);
	}
	if (ljson_serialize_elem(lvec_at(elem->data, idx), output) == -1)
		return (-1);
	return (0);
}

int ljson_serialize_array(json_item_t *elem, char **output)
{
	int idx = -1;
	int size = lvec_size(elem->data);

	*output = lstr_append(*output, "[");
	if (*output == NULL)
		return (-1);
	while (++idx < size)
		if (internal_ljson_serialize_array_helper(output, idx, elem) ==
			-1)
			return (-1);
	*output = lstr_append(*output, "]");
	if (*output == NULL)
		return (-1);
	return (0);
}