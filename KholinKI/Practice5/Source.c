#include <stdio.h>
#include <windows.h>
#include "Sorts.h"

int main() {
	int a[10] = { 152,152,12,800,991,7,-205,-9,12 }; //unordered array #1
	int b[10] = { 100,-10,60,400,-1000,30,-50,29,0,5 }; //unordered array #2
	int c[10] = { -11,-59,-12131,893,1,3,0,-2,100000,40}; //unorderd array #3
	int i; //counter
	ChoiceSort(a, 10); //call sort choice
	InsertSort(b, 10); //call sort insert
	QuickSort(c, 0,9); //call quick
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);	//sorted by Choice
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]);	//sorted by Insert
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", c[i]);	//sorted by Quick
	}
	return 0;
}

//начать работу с файлами
