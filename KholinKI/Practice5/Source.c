#include <stdio.h>
#include <windows.h>
#include "Sorts.h"
#include <time.h>
#include <string.h>



int main() {
	int answer;
	char path; //path directory
	printf("Hello, welcome to the file manager! Choose a method for sorting file structures from the menu: \n");
	printf("Sorting menu: \n");
	printf("1. Sorting by choice\n");									//Greeting and sorting selection
	printf("2. Sorting by inserts\n");
	printf("3. Hoare Sorting\n");
	scanf("%d", &answer); //Making choices
	

	switch (answer) {
		case 1:	
			printf("Enter the path for the directory by which you want to sort the content:\n");
			scanf("%s", &path); //file path
			path(path);
			break;
		case 2:															
			break;
		case 3:
			break;
	}
	return 0;
}


