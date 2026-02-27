#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(arr[i] < arr[j])
			{
				int temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
}

int* generateArray(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		*(arr+i) = rand()%15;
	}
	return arr;
}

void printArray(int *arr, int size)
{
	printf("[ ");
	for(int i = 0; i < size - 1; i++)
	{

		printf("%d, ",*(arr+i));
	}
	printf("%d ]\n",*(arr+(size-1)));
}

int getKthLargest(int *arr, int k, int size)
{
	if(k > size)
	{
		printf("Invalid value for k");
		return 0;
	}

	int *arrK = (int*)malloc(sizeof(int)*k);
	
	int i = 0;

	while(i < k)
	{
		*(arrK + i) = *(arr+i);
		i++;
	}

	bubbleSort(arrK, k);

	while( i < size)
	{

		
		if(*(arrK+(k-1)) < *(arr + i))
		{
			*(arrK + (k - 1)) = *(arr + i);
			bubbleSort(arrK,k);
		}
		i++;
	}
	return *(arrK+(k-1));
}

void main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Please provide only one argument for the size of the array.\n");
		return;
	}
	srand(time(NULL));
	int arr_size = atoi(argv[1]);
	int* arr = (int*)malloc(sizeof(int)*arr_size);
	
	arr = generateArray(arr, arr_size);
	
	printArray(arr, arr_size);
	int kthLargest = getKthLargest(arr, 3, arr_size);

	printf("The third largest is %d\n",kthLargest);
	free(arr);

}
