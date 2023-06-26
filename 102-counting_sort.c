#include "sort.h"
/**
 * max_num - fun that get the max number of an array
 * @array: pointer of the array
 * @size: size of the array
 * Return: max number
 */
int max_num(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size - 1; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * create_array_zeros- fun that create array of int filled with zeros
 * @k: size of the array we wanna create
 * Return: pointer to an array
 */
int *create_array_zeros(size_t k)
{
	int *count;
	size_t i;

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(count);
		return (NULL);
	}
	for (i = 0 ; i < k + 1 ; i++)
		count[i] = 0;
	return (count);
}

/**
 * counting_sort - fun that sort array using the counting algorithm
 * @array: pointer to an array we want to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t k, i, j;
	int m;
	int *count, *output;
	/* get the k */
	k = max_num(array, size);
	/* create array and fill it with zeros */
	count = create_array_zeros(k);
	/* count how many of each num in the array */
	for (i = 0; i < size; i++)
	{
		j = array[i];
		count[j] += 1;
	}
	/* sum the counts */
	for (i = 1; i < k + 1; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	output = create_array_zeros(size);

	for (m = size - 1; m >= 0; m--)
	{
		j = array[m];
		count[j] -= 1;
		output[count[j]] = array[m];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
