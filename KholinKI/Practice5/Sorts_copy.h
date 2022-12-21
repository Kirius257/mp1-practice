#pragma once


void InsertSort(int* arr, int size,int*ind) {
	int i, j, tmp,tmp2;
	for (i = 0; i < size; i++) {
		tmp = arr[i]; //main variable(saved)
		tmp2 = ind[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp) { //A pairwise comparison of tmp with previous elements.
			arr[j + 1] = arr[j];//swapping tmp in place arr[j]
			arr[j] = tmp; //insert saved element
			ind[j + 1] = ind[j];
			ind[j] = tmp2;
			j--; //next iteration
		}
	}
}

void ChoiceSort(int* arr, int size,int*index) {//sorting by selection
	int i, min, ind, j,tmp;
	for (i = 0; i < size; i++) {
		min = arr[i];  //The minimum becomes element i
		ind = i; //save ind minimum`s
		for (j = i + 1; j < size; j++) {
			if (arr[j] < min) { //classical comparison of elements in an array, starting from the second
				min = arr[j];
				ind = j; //save index min
			}
		}
		tmp = index[ind];
		arr[ind] = arr[i];
		index[ind] = index[i];
		//SWAPPING: we put a new one in place of the old minimum
		arr[i] = min;
		index[i] = tmp;
	}
}


int partition(int list[], int start, int pivot)
{
	int tmp1, tmp2; //saved 
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

void QuickSort(int list[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(list, start, end);//get index reference element

		QuickSort(list, start, pivot - 1);//array with smaller elements
		QuickSort(list, pivot + 1, end);//array with bigger elements
	}
}