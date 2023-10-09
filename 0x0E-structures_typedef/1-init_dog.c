#include "dog.h"

/**
 * init_dog - function that initialize a variable of type struct dog
 * @d: pointer to struct dog
 * @name: pointer to char name which is dog's name
 * @age: age of the dog
 * @owner: pointer to char owner of the dog
 * Return: NULL
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
