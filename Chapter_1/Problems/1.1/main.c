#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber()
{
	
	return rand()%50;
}

void printElementsInArray(int array[], int size)
{
	
	printf("[");
	for(int i = 0; i < size - 1; i++)
	{
		printf("%d, ",array[i]);
	}
	printf("%d ]\n",array[size-1]);
}

void bubbleSortArray(int *arr, int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(arr[i] <= arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	const int arr_size = atoi(argv[1]);
	printf("Your array will contain %d elements.\n",arr_size);
	int arr[arr_size] = {};

	for(int i = 0; i < arr_size; i++)
	{
		arr[i] = generateRandomNumber();
	}
	printf("Array: ");
	printElementsInArray(arr, arr_size);
	bubbleSortArray(arr, arr_size);
	printElementsInArray(arr, arr_size);

	printf("If k is the kth largest number in an array from the array defined above, what do you want k to be? ");
	int k = 0;
	scanf("%d",&k);

	if(k > arr_size)
	{
		printf("Invalid value for k. k must be less than the size of the array.\n");
		return -1;
	}

	printf("You wanted %d.\n",arr[k-1]);
	return 0;
}
