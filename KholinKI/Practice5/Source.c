#include <stdio.h>
#include <windows.h>
#include "Sorts.h"
#include <time.h>
#include <string.h>
#include <conio.h>
#include <io.h>
#include <direct.h>
#include <locale.h>


char path[100]; //path directory


int main() {
	setlocale(LC_ALL,"rus");
	int answer;
	char save;
	char path[300]; //path directory
	save = path[0];
	printf("Hello, welcome to the file manager! Choose a method for sorting file structures from the menu: \n");
	printf("Sorting menu: \n");
	printf("1. Sorting by choice\n");									//Greeting and sorting selection
	printf("2. Sorting by inserts\n");
	printf("3. Hoare Sorting\n");
	scanf_s("%d", &answer); //Making choices
	getchar();
	switch (answer)
	{
		case 1: 
		{
			printf("Enter the path for the directory where you want to sort the content: ");
			printf("\n");
			gets(path);
			struct _finddata_t data;
			HANDLE cursor;
			cursor = FindFirstFile(path, &data);
			if (cursor != INVALID_HANDLE_VALUE) {
				do{
					printf("%s", data.name);
				} while ((FindNextFile(cursor, &data))==0);
				FindClose(cursor);
			}
			
		}
	}
	return 0;
}


