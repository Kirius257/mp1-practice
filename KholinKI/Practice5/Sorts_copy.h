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


void swap(int* a, int* b) { // swap(&a, &b);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort_increase(int* a, int low, int high, int* indexes) {
	int mid;
	int l = low, h = high;
	mid = a[(l + h) / 2];
	while (l < h) {
		while (a[l] < mid)
			l++;
		while (a[h] > mid)
			h--;
		if (l <= h) {
			swap(&a[l], &a[h]);
			swap(&indexes[l], &indexes[h]);
			l++;
			h--;
		}
	}
	if (low < h)
		quick_sort_increase(a, low, h,indexes);
	if (l < high)
		quick_sort_increase(a, l, high,indexes);
}
void quick_sort_decrease(int* a, int low, int high, int* indexes) {
	int mid;
	int l = low, h = high;
	mid = a[(l + h) / 2];
	while (l < h) {
		while (a[l] > mid)
			l++;
		while (a[h] < mid)
			h--;
		if (l <= h) {
			swap(&a[l], &a[h]);
			swap(&indexes[l], &indexes[h]);
			l++;
			h--;
		}
	}
	if (low < h)
		quick_sort_decrease(a, low, h,indexes);
	if (l < high)
		quick_sort_decrease(a, l, high,indexes);
}
void quick_sort(int* a, int n, int mode, int*indexes) {
	if (mode == 0)  quick_sort_increase(a, 0, n - 1, indexes);
	if (mode == -1) quick_sort_decrease(a, 0, n - 1, indexes);
}
