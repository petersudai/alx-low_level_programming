#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of array
 *
 * Return: pointer to created sorted hash table, NULL failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	memset(ht->array, 0, sizeof(shash_node_t *) * size);
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - adds a key/value pair to sorted hash table
 * @ht: sorted hash table
 * @key: key, string
 * @value: value corresponding to a key
 *
 * Return: success 1, 0 failure
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current_node;

	if (ht == NULL || key || NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	current_node = ht->array[index];

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	while (current_node != NULL && strcmp(current_node->key, key) < 0)
	{
		current_node = current_node->snext;
	}

	if (current_node == NULL)
	{
		new_node->sprev = ht->stail;
		new_node->snext = NULL;

		if (ht->stail != NULL)
			ht->stail->snext = new_node;
		ht->stail = new_node;

		if (ht->shead == NULL)
			ht->shead = new_node;
	}
	else
	{
		new_node->sprev = current_node->sprev;
		new_node->snext = current_node;

		if (current_node->sprev != NULL)
			current_node->sprev->snext = new_node;
		current_node->snext = new_node;

		if (new_node->sprev == NULL)
			ht->shead = new_node;
	}

	ht->array[index] = new_node;

	return (1);
}

/**
 * shash_table_get - retrieves value associated with a key in sorted hash table
 * @ht: sorted hash table
 * @key: key to search for
 *
 * Return: value associated with element, NULL if key not found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	current_node = ht->array[index];

	while (current_node != NULL && strcmp(current_node->key, key) != 0)
		current_node = current_node->snext;

	return ((current_node != NULL) ? current_node->value : NULL);
}

/**
 * shash_table_print - prints hash table using sorted linked list
 * @ht: sorted hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");
	for (current_node = ht->shead; current_node != NULL;
			current_node = current_node->snext)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		if (current_node->snext != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints hash table in rev order using linked list
 * @ht: sorted hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");
	for (current_node = ht->stail; current_node != NULL;
			current_node = current_node->sprev)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		if (current_node->sprev != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes sorted hash table frees all allocated memory
 * @ht: sorted hash table to delete
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current_node, *next_node;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];
		while (current_node != NULL)
		{
			next_node = current_node->next;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
			current_node = next_node;
		}
	}
	free(ht->array);
	free(ht);
}
