#include <iostream>
#include <time.h>
using namespace std;

int a;
int b;
void check1() {
	a = 6;
	b = a + 5;
	b *= 2;
}

void check2() {
	int c = 6;
	int d = c + 5;
	d *= 2;

}

int main() {
	int start;

	start = clock();
	for (int i = 0; i<10000000; i++) {
		check1();
	}
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i<10000000; i++) {
		check2();
	}
	cout << clock() - start << endl;
	return 0;
}