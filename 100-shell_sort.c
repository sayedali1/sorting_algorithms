#include "sort.h"
/**
 * calc_interval - fun that calc the sequnce of intervals
 * @size: size of the array we want to calc the interval for
 * Return: the interval
 */
size_t calc_interval(size_t size)
{
	size_t interval = 0;

	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}
	return (interval);
}

/**
 * shell_sort - fun that sort an array using shell sort algorthim
 * @array: pointer to an array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = calc_interval(size);
	size_t outer, inner;
	int temp;
	/* walk through the intervals */
	if (array == NULL || size < 2)
		return;

	while (interval > 0)
	{
		/* walk through the array */
		for (outer = interval; outer < size; outer++)
		{

			temp = array[outer];
			/* check to swap through the two element across the gap */
			for (inner = outer; inner >= interval &&
			array[inner - interval] > temp; inner = inner - interval)
			{
				array[inner] = array[inner - interval];
			}
			array[inner] = temp;
		}
		print_array(array, size);
		/* calc the intervals for next step */
		interval = calc_interval(interval);
	}
}
