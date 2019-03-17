#include <iostream>
#include <time.h>
using namespace std;

void check1(int n) {
	if (n == 0)
		return;
	check1(n - 1);
}

int m;

void check2() {
	if (m == 0)
		return;
	m--;
	check2();
}

int main() {
	int start;

	start = clock();
	check1(200000);
	cout << clock() - start << endl;

	start = clock();
	m = 200000;
	check2();
	cout << clock() - start << endl;
	return 0;
}