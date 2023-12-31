#include "sort.h"
/**
 * calc_interval - fun that calc the sequnce of intervals
 * @size: size of the array we want to calc the interval for
 * Return: the interval
 */
size_t calc_interval(size_t size)
{
	int interval = 0;

	while (interval < (int)size)
	{
		interval = (interval * 3) + 1;
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
	int interval = calc_interval(size);
	int outer, inner;
	int temp;
	/* walk through the intervals */

	for (interval = (interval - 1) / 3;  interval > 0;
	interval = (interval - 1) / 3)
	{
		/* walk through the array */
		for (outer = interval; outer < (int)size; outer++)
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
	}
}
