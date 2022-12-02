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

int partition(int list[], int start, int pivot)
{
	int tmp1,tmp2; //saved 
	int i = start; //start sorting to index 0
	while (i < pivot)
	{
		tmp1 = list[i];
		tmp2 = list[pivot - 1];
		if (list[i] > list[pivot] && i == pivot - 1)//the last sorting step, when the final element is to be thrown
		{
			list[i] = list[pivot];//IS THE POSITION OF THE REFERENCE ELEMENT THAT THE FUNCTION WILL RETURN!
			list[pivot] = tmp1;
			pivot--;
		}

		else if (list[i] > list[pivot])//if an element larger than the reference element is found
		{
			list[pivot - 1] = list[pivot];//move the reference element one unit to the left
			list[pivot] = tmp2;//and place the larger element to the right of the reference
			list[i] = list[pivot];
			list[pivot] = tmp1; //similar to the previous one swap
			pivot--;
		}

		else i++;//to the next element of the array for comparison with the reference element
	}
	return pivot;
}

void quickSort(int list[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(list, start, end);//get index reference element

		quickSort(list, start, pivot - 1);//array with smaller elements
		quickSort(list, pivot + 1, end);//array with bigger elements
	}
}


int main() {
	int a[10] = { 152,152,12,800,991,7,-205,-9,12 }; //unordered array #1
	int b[10] = { 100,-10,60,400,-1000,30,-50,29,0,5 }; //unordered array #2
	int c[10] = { -11,-59,-12131,893,1,3,0,-2,100000,40}; //unorderd array #3
	int i; //counter
	choice_sort(a, 10); //call sort choice
	insert_sort(b, 10); //call sort insert
	quickSort(c, 0,9); //call quick
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
