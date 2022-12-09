#include <stdio.h>
#include <windows.h>
#include "Sorts.h"
#include <time.h>
#include <string.h>
#include <conio.h>

char path[100]; //path directory


int main() {
	int answer;
	char save;
	char path[100]; //path directory
	save = path[0];
	printf("Hello, welcome to the file manager! Choose a method for sorting file structures from the menu: \n");
	printf("Sorting menu: \n");
	printf("1. Sorting by choice\n");									//Greeting and sorting selection
	printf("2. Sorting by inserts\n");
	printf("3. Hoare Sorting\n");
	scanf_s("%d", &answer); //Making choices
	getchar();
	
	if (answer == 1) {
		path[0] = save;
		printf("Enter the path for the directory by which you want to sort the content:");
		fgets(path, 100, stdin); //file path
		puts(path);
	}
	else if (answer == 2) {
		printf("Enter the path for the directory by which you want to sort the content:");
		fgets(path, 100, stdin); //file path
		puts(path);
	}
	else {
		printf("Enter the path for the directory by which you want to sort the content:");
		fgets(path, 100, stdin); //file path
		puts(path);
	}
	/*
	* Следующая задача:
	* Придумать,как перейти в директорию
	*/
	return 0;
}


