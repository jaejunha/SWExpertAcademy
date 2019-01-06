#include <iostream>

using namespace std;

int* quick(int *arr, int l, int r) {
	int i = l;
	int j = r;
	int pivot = arr[(l + r) / 2];

	do {
		while (arr[i]<pivot)
			i++;
		while (arr[j]>pivot)
			j--;
		if (i <= j)
			swap(arr[i++], arr[j--]);
	} while (i <= j);

	if (l<j)
		quick(arr, l, j);
	if (i<r)
		quick(arr, i, r);
}

int main()
{
	int arr[10] = { 10,6,7,5,1,8,2,4,3,9 };
	for (int i = 0; i<10; i++)
		cout << arr[i] << " ";
	cout << endl;

	quick(arr, 0, 9);

	for (int i = 0; i<10; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}