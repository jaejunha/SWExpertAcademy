#include <iostream>
#include <time.h>
using namespace std;

void check1(int n[1000000], int i) {
	n[i] = 1;
}

void check2(int *n, int i) {
	*(n + i) = 1;
}

int main() {
	int start;

	int n[1000000];

	start = clock();
	for (int i = 0; i<1000000; i++)
		check1(n, i);
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i<1000000; i++)
		check2(&n[0], i);
	cout << clock() - start << endl;
	return 0;
}