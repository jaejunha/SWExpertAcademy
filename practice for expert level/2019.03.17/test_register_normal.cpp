#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int start;

	start = clock();
	for (register int i = 0; i<10000000; i++);
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i<10000000; i++);
	cout << clock() - start << endl;
	return 0;
}