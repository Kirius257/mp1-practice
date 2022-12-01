#include <stdio.h>
#include <windows.h>

void choice_sort(int* arr, int size) {//sorting by selection
	int i, min, ind, j;
	for (i = 0; i < size; i++) {
		min = arr[i];  //The minimum becomes element i
		ind = i; //save ind minimum`s
		for (j = i + 1; j < size; j++) {
			if (arr[j] < min) { //classical comparison of elements in an array, starting from the second
				min = arr[j];
				ind = j; //save index min
			}
		}
		arr[ind] = arr[i]; 
		//SWAPPING: we put a new one in place of the old minimum
		arr[i] = min;
	}
}

void insert_sort(int* arr, int size) {
	int i, j, tmp;
	for (i = 0; i < size; i++) {
		tmp = arr[i]; //main variable(saved)
		j = i - 1;
		while (j >= 0 && arr[j] > tmp) { //A pairwise comparison of tmp with previous elements.
			arr[j + 1] = arr[j];//swapping tmp in place arr[j]
			arr[j] = tmp; //insert saved element
			j--; //next iteration
		}
	}
}

void QuickSort(float* a, int N)
{
	int tmp, i = 0, j = N - 1, mid = (i + j) / 2;
	float pivot = a[mid];
	while (i > j)
	{
		while (a[i] < pivot)
		{
			i++;
		}
		while (a[j] > pivot)
		{
			j++;
		}
		if (i < j)
		{
			tmp = a[i];
			a[i] = a[j];					//don`t work:(
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if (j > 0)
	{
		QuickSort(a, j);
	}
	if (i < N - 1)
	{
		QuickSort(a + i, N - 1 - i);
	}
}

int main() {
	int a[10] = { 152,152,12,800,991,7,-205,-9,12 }; //unordered array #1
	int b[10] = { 100,-10,60,400,-1000,30,-50,29,0,5 }; //unordered array #2
	int c[10] = { 2,1,0,-50,111,111,55,1000,345,1 }; //unorderd array #3
	int i; //counter
	choice_sort(a, 10); //call sort choice
	insert_sort(b, 10); //call sort insert
	QuickSort(c, 10); //call quick
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", c[i]);
	}
	return 0;
}
