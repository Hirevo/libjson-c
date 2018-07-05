/*
** EPITECH PROJECT, 2018
** json
** File description:
** base
*/

#include "../intern_json.h"

int ljson_parse_elem(char *raw, int idx, hmap_t *root)
{
	json_type_t type;
	char *key;
	void *data;

	idx = ljson_parse_str(raw, idx, (void **)&key);
	if (idx == -1 || lhmap_get(root, key) != NULL || raw[idx++] != ':')
		return (-1);
	type = ljson_find_type(raw, idx);
	if (type == JSON_UNKNOWN)
		return (-1);
	idx = ljson_assign_value(raw, idx, type, &data);
	if (idx == -1 ||
		lhmap_set(root, key, ljson_item_new(type, data)) == false)
		return (-1);
	free(key);
	return (idx);
}

json_item_t *ljson_init_root(char *raw, int idx)
{
	json_type_t type = ljson_find_type(raw, idx);
	void *data;

	if (type == JSON_UNKNOWN ||
		ljson_assign_value(raw, idx, type, &data) == -1)
		return (0);
	return (ljson_item_new(type, data));
}

json_item_t *ljson_build_tree(char *raw)
{
	if (raw == 0 || (raw[0] != '{' && raw[0] != '['))
		return (0);
	return (ljson_init_root(raw, 0));
}