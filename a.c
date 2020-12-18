#define _CRT_SECURE_NO_WARNINGS
#define N 255 
#define BLOCK_SIZE 5
#include <stdio.h>
#include <stdlib.h>

int* input(int* len)
{
	int count = 0;
	int x = 1;
	int arr[5] = {0};
	int** list = NULL;
	int** mas = (int**) malloc(1 * sizeof(int*));
	int* array;

	while (x != 0)
	{
		while(scanf("%d", &x) != 1 || getchar() != '\n')
		{
			printf("Error, try again\n");
			while (getchar() != '\n');
		}
		if (x)
			arr[count++ % BLOCK_SIZE] = x;
		if (x && count % BLOCK_SIZE == 0)
		{
			list = (int**) calloc(((count / BLOCK_SIZE) +1 ), sizeof(int*));
			list[(count / BLOCK_SIZE) - 1] = (int*) calloc(BLOCK_SIZE, sizeof(int));

			for (int i = 0; i < (count / BLOCK_SIZE) - 1; ++i)
				list[i / BLOCK_SIZE] = (int*) mas[i / BLOCK_SIZE];

			for (int j = 0; j < BLOCK_SIZE; ++j)
				list[(count / BLOCK_SIZE) - 1][j] = (int) arr[j];
			mas = (int**) list;
		}
	}
	printf("%d - count\n", count);
	printf("%d", count/BLOCK_SIZE);
	printf("%d", count % BLOCK_SIZE);
	if (count % BLOCK_SIZE)
	{
		printf("%d", (int) count/BLOCK_SIZE);
		mas[count/BLOCK_SIZE] = (int*) malloc(count % BLOCK_SIZE * sizeof(int));
		for (int i = 0; i < count % BLOCK_SIZE; ++i)
			mas[count/BLOCK_SIZE][i] = arr[i];
	}

	array = (int*) malloc((count) * sizeof(int));
	for (int i = 0; i < count; ++i)
		array[i] = mas[i / BLOCK_SIZE][i % BLOCK_SIZE];
	for (int i = 0; i < count/BLOCK_SIZE; ++i)
	{
		free(mas[i]);
	}
	free(mas);

	*len = count - 1;
	return array;

}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void erase(int* arr, unsigned int  size, unsigned int number) 
{
	arr[number] = 0;
	for (int i = number; i < size; ++i)
		swap(&arr[i], &arr[i+1]);
}

int find(int* arr, int len)
{
        int check = 0;
        for (int k = 1; k < len - 1; k++) //ищем локальные минимумы 
                if ((arr[k] < arr[k - 1]) && (arr[k] < arr[k + 1]))
                {
			erase(arr, len, k);
                        check++;
                }
        return check;
}


int main()
{
        int  len = 0;
	int* arr = input(&len);
        if (find(arr, len) != 0)
                for (int i = 0; i <= len; i++)
                        printf("%d ", arr[i]);
        else
                printf("The array does not contain local minima");
	putchar('\n');
        return 0;
}
