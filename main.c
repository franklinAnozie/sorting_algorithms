#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	/**
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7, 56, 87, 34, 91};
    int array[] = {43, 7, 78, 22, 64, 75, 86, 60, 57, 56, 12, 94, 99, 55, 67, 10, 27, 23, 14, 38, 89, 24, 39, 92, 35, 97, 88, 2, 46, 93};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	*/
	int array[] = {695, 341, 919, 39, 766, 680, 762, 152, 791, 475,
					66, 827, 508, 80, 126, 584, 837, 443, 342, 773,
					121, 956, 125, 748, 538, 990, 706, 90, 111, 41,
					638, 330, 576, 661, 927, 711, 287, 336, 526, 916,
					260, 710, 259, 378, 636, 694, 701, 175, 500, 266};

	size_t n = sizeof(array) / sizeof(array[0]);

	printf("n: %ld\n", n);
	print_array(array, n);
	printf("n: %ld\n", n);
	printf("\n");
	printf("n: %ld\n", n);
	shell_sort(array, n);
	printf("n: %ld\n", n);
	printf("\n");
	printf("n: %ld\n", n);
	print_array(array, n);
	printf("n: %ld\n", n);

	return (0);
}
