#include "shell.h"
/**
 * _memcpy - Func copies memory
 * @dest: Memory dest
 * @src: Memory area
 * @n: Num of bytes
 *
 * Return: Ptr
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int u;

	for (u = 0; u < n; u++)
	{
		dest[u] = src[u];
	}
	return (dest);
}
/**
 * custom_realloc - Func allocates memory
 * @ptr: Ptr
 * @size: Size
 * Return: New ptr
 */
void *custom_realloc(void *ptr, size_t size)
{
	void *newptr;

	if (size == 0)
	{
		if (ptr)
		{
			free(ptr);
		}
		return (NULL);
	}
	newptr = malloc(size);
	if (!newptr)
	{
		errno = ENOMEM;
		free(ptr);
		return (NULL);
	}
	if (ptr)
	{
		_memcpy(newptr, ptr, size);
	}
	free(ptr);
	return (newptr);
}
