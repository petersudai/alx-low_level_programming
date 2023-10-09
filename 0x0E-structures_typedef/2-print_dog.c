#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints information about a dog
 * @d: Pointer to struct dog
 *
 * Description: function prints the name, age and owner of a dog. If any
 * of these elements are NULL, it prints (nil) instead.
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
		printf("Age: %f\n", d->age);
		printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
	}
}
