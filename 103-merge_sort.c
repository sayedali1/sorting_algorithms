#include "sort.h"

/**
 * merge_topDown - fun that merge two arrays
 * @arrayA: the first array we wanna merge
 * @arrayB: the sec array we want to merge
 * @iStart: the start index of the array
 * @iMiddle: the middle index of the array
 * @iEnd: the last index of the array
 */
void merge_topDown(int *arrayA, int *arrayB, int iStart, int iMiddle, int iEnd)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arrayA + iStart, iMiddle - iStart);
	printf("[right]: ");
	print_array(arrayA + iMiddle, iEnd - iMiddle);

	i = iStart;
	j = iMiddle;

	for (k = iStart; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || arrayA[i] <= arrayA[j]))
		{
			arrayB[k] = arrayA[i];
			i++;
		}
		else
		{
			arrayB[k] = arrayA[j];
			j++;
		}

	}
	printf("[Done]: ");
	print_array(arrayB + iStart, iEnd - iStart);
}
/**
 * merge_sort_spilt_topDown - fun that split array into two arrays
 * @arrayA: the array we want to split
 * @arrayB: copy of the array
 * @iStart: the first index of the array
 * @iEnd: the last index of the array
 */
void merge_sort_spilt_topDown(int *arrayA, int *arrayB, int iStart, int iEnd)
{
	int iMiddle = 0;

	if ((iEnd - iStart) < 2)
		return;
	iMiddle = (iStart + iEnd) / 2;

	merge_sort_spilt_topDown(arrayA, arrayB, iStart, iMiddle);
	merge_sort_spilt_topDown(arrayA, arrayB, iMiddle, iEnd);
	merge_topDown(arrayA, arrayB, iStart, iMiddle, iEnd);

	for (iMiddle = iStart; iMiddle < iEnd; iMiddle++)
		arrayA[iMiddle] = arrayB[iMiddle];
}

/**
 * merge_sort - fun that sort array of numbers using merge sort algorithm
 * using topdown aproch
 * @array: the array we want to sort
 * @size:size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *cp_array = NULL;
	int i;

	cp_array = malloc(sizeof(int) * (size));
	if (cp_array == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		cp_array[i] = array[i];

	merge_sort_spilt_topDown(array, cp_array, 0, size);
	free(cp_array);
}
