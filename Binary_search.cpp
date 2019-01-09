#include <iostream>
using namespace std;
int binarySearch(int arr[5], int s, int v) {
	int l = 0;
	int r = s - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] == v) {
			return mid;
		}
		else if (arr[mid]>v) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}
int main() {
	int arr[] = { 1,2,6,8,10 };
	cout << binarySearch(arr, 5, 7);
}