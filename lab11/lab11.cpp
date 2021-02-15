#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX_RANDOM_VALUE 100.0

int main()
{
	double src_arr[N] = { 0 };

	double* new_arr = NULL;
	unsigned int new_arr_size = 0;

	unsigned int max_sector_index = 0;

	unsigned int valid_sector_cnt = 0;



	srand((unsigned int)time(NULL));
	for (unsigned int i = 0; i < N; i++)
		src_arr[i] = (double)rand() / (double)(RAND_MAX / MAX_RANDOM_VALUE);

	printf("SOURCE ARRAY (SIZE = %d) :\n\n", N);
	for (unsigned int i = 0; i < N; i++)
		printf("%d = %f\n", i, src_arr[i]);



	for (unsigned int i = 0, j = 0; i < N - 1; i++)
	{
		if (src_arr[i] > src_arr[i + 1])
			continue;


		valid_sector_cnt++;
		while (src_arr[i] <= src_arr[i + 1])
		{
			i++;
			j++;
		}

		if (j >= new_arr_size)
		{
			new_arr_size = j + 1;
			max_sector_index = i - j;
		}

		j = 0;
	}

	new_arr = (double*)malloc(new_arr_size * sizeof(double));
	for (unsigned int i = 0, j = max_sector_index; i < new_arr_size; i++, j++)
		new_arr[i] = src_arr[j];

	printf("\n===============================\n\nNUMBER OF VALID SECTORS = %d\n\nNEW ARRAY (SIZE = %d) :\n\n", valid_sector_cnt, new_arr_size);
	for (unsigned int i = 0; i < new_arr_size; i++)
		printf("%d = %f\n", i, new_arr[i]);

	free(new_arr);

	return 0;
}