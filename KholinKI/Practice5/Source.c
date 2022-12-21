#include <stdio.h>
#include <windows.h>
#include "Sorts_copy.h"
#include <time.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#define N 2000

struct files {
	char name[260];
	unsigned long size;
};
struct files new_data[2000];

void copy(char* names, wchar_t* data) {
	int i=0;
	while (strcmp("\0", &data[i]) != 0) {
		names[i] = data[i];
		i++;
	}
	strcpy(&names[i], "\0");
}


long sizes[N];
 
 void File_manager() {
	 int counter = 0;
	 int save;
	 int saved_sizes[N];
	 char path[500]; //path directory
	 char names[500];
	 int i, j;
	 for (i = 0; i < N; i++) {
		 sizes[i] = -1;
	 }
	 printf("Enter the path for the directory where you want to sort the content: ");
	 printf("\n");
	 gets(path);
	 strcat(path, "/*");
	 WIN32_FIND_DATA data;
	 HANDLE cursor;
	 cursor = FindFirstFileA(&path, &data);
	 if (cursor != INVALID_HANDLE_VALUE) {
		 while (FindNextFile(cursor, &data) != 0) {//while files have
			 copy(names, data.cFileName);//mass of names
			 if (strcmp(names, "..") == 0) {
				 continue;
			 }
			 if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {//display only files, skip folders
				 new_data[counter].size = data.nFileSizeLow;// write the file size in the new structure
				 strcpy(&new_data[counter].name, &names);//copy the name of the names array into the names array of the structure
				 sizes[counter] = new_data[counter].size;// write the file sizes in the file size array
				 counter++;
			 }
		 }
		 FindClose(cursor);
	 }
 }

 void output_sizes() {//
	 int i, j;
	 int save;
	 int saved_sizes[N];
	 for (i = 0; i < N; i++) {
		 for (j = 0; j < N; j++) {	//
			 save = new_data[j].size;
			 if (sizes[i] == new_data[j].size) {
				 if (new_data[j].size != -1) {
					 printf("%s      %ldBytes\n", new_data[j].name, new_data[j].size);
					 saved_sizes[j] = new_data[j].size; //Backup field
					 new_data[j].size = -1;
				 }
			 }
		 }
	 }
 }

int main() {
	system("chcp 1251");
	setlocale(LC_ALL,"rus");
	int answer; //for communication with user
	int status = 1;
	printf("Hello, welcome to the file manager! Choose a method for sorting file structures from the menu: \n");
	do{
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
			File_manager();
			clock_t begin = clock();
			ChoiceSort(sizes, N);
			clock_t end = clock();
			output_sizes();
			long double q = end;
			q /= 1000000;
			printf("\n");
			printf("Time of Choice Sort: %lf.\n", q);
			memset(&new_data, 0, sizeof(new_data));
			printf("Do you want change method of sorts?(1/0)\n");
			scanf("%d", &status);
			break;
		}
		case 2:
		{
			File_manager();
			clock_t begin = clock();
			InsertSort(sizes, N);
			clock_t end = clock();
			output_sizes();
			long double q = end;
			q /= 1000000;
			printf("\n");
			printf("Time of Insert Sort: %lf.\n", q);
			memset(&new_data, 0, sizeof(new_data));
			printf("Do you want change method of sorts?(1/0)\n");
			scanf("%d", &status);
			break;
		}
		case 3:
		{
			File_manager();
			clock_t begin = clock();
			QuickSort(sizes, 0, N);
			clock_t end = clock();
			output_sizes();
			long double q = end;
			q /= 1000000;
			printf("\n");
			printf("Time of Quick Sort Sort: %lf.\n", q);
			memset(&new_data, 0, sizeof(new_data));
			printf("Do you want change method of sorts?(1/0)\n");
			scanf("%d", &status);
			break;
		}
		}
	} while (status == 1);
	printf("Have a nice day!");
	return 0;
}


