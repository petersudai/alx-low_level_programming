#include "dog.h"

/**
 * free_dog - function that frees dogs.
 * @d: Pointer to the dog_t structure to be freed
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
