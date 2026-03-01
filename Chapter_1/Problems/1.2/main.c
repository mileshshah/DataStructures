#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char** createWordPuzzle(int sizeOfPuzzle)
{
	char** puzzle = (char**)malloc(sizeof(char*)* sizeOfPuzzle);
	for(int i = 0; i < sizeOfPuzzle; i++)
	{
		*(puzzle+i) = malloc(sizeof(char)* sizeOfPuzzle);
	}
	
	
	for(int i = 0; i < sizeOfPuzzle; i++)
	{
		for(int j = 0; j < sizeOfPuzzle; j++)
		{
			*(*(puzzle+i)+j) =  rand()%26 + 97;
		}
		
	}
	return puzzle;
}

void printPuzzle(char **puzzle, int sizeOfPuzzle)
{
	printf("Here is the puzzle that you have created: \n");

	for(int i = 0; i < sizeOfPuzzle; i++)
	{
		for(int j = 0; j < sizeOfPuzzle; j++)
		{
			printf("%c ",*(*(puzzle+i)+j));
		}
		printf("\n");		
	}
}

bool findMatch(char** matrix, char *word, int x, int y, int wordIndex, int sizeOfPuzzle, int wordLength)
{
	
	if( x < 0 || x >= sizeOfPuzzle || y < 0 || y >= sizeOfPuzzle)
	{
		printf("Invalid index.\n");
		return false;
	}
	if( wordIndex == wordLength)
	{
		printf("Word exists.\n");
		return true;
	}

	if(*(*(matrix+x)+y) == *(word+wordIndex))
	{
		char temp = *(*(matrix+x)+y);
		*(*(matrix+x)+y) = '#';
		bool res = findMatch(matrix, word, x + 1, y, wordIndex + 1, sizeOfPuzzle, wordLength) ||
		findMatch(matrix, word, x, y + 1, wordIndex + 1, sizeOfPuzzle, wordLength) ||
		findMatch(matrix, word, x - 1, y, wordIndex + 1, sizeOfPuzzle, wordLength) ||
		findMatch(matrix, word, x, y - 1, wordIndex + 1, sizeOfPuzzle, wordLength);
		*(*(matrix+x)+y) = temp;
		return res;
	}
	return false;
	
}

bool wordExists(char** matrix, char* word, int wordLength, int wordPuzzleLength)
{
	for(int i = 0; i < wordPuzzleLength - 1; i++)
	{
		for(int j = i + 1; j < wordPuzzleLength; j++)
		{
			if(*(*(matrix+i)+j) == *word)
			{
				bool wordFound = findMatch(matrix, word, i, j, 0, wordPuzzleLength, wordLength);
				return wordFound;
			}
		}
	}
	return false;
}

void main(int argc, char *argv[])
{	
	srand(time(NULL));
	if(argc != 2)
	{
		printf("Please provide a number for the dimensions of the sqaure character matrix that will contain the letters of your puzzle.\n");
		return;
	}
	int sizeOfPuzzle = atoi(argv[1]);
	char **puzzle = createWordPuzzle(sizeOfPuzzle);
	printPuzzle(puzzle, sizeOfPuzzle);
	
	char* wordToFind = (char*)malloc(sizeof(char)*sizeOfPuzzle);
	printf("What is the word that you want to find? ");
	scanf("%s",wordToFind);

	if(wordExists(puzzle, wordToFind, sizeOfPuzzle, sizeOfPuzzle) == true)
	{
		printf("Word found.\n");
	}
	else{
		printf("Word not found.\n");
	}

	for(int i = 0; i < sizeOfPuzzle; i++)
	{
		free(*(puzzle+i));
	}
	free(puzzle);
}
