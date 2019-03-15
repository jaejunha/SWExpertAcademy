#include <iostream>
#include <ctime>
using namespace std;

long long pow_full1(int a, int b) {
	long long ret = 1;
	for (int i = 1; i <= b; i++) {
		ret *= a;
	}
	return ret;
}

long long pow_full2(int a, int b) {
	long long ret = 1;
	for (int i = 1; i <= b; i++, ret *= a);
	return ret;
}


long long pow_rec1(int a, long long b) {

	long long ret;

	if (b == 1)
		return a;

	if (b % 2 == 0) {
		ret = pow_rec1(a, b / 2);
		return ret*ret;
	}
	else {
		ret = pow_rec1(a, (b - 1) / 2);
		return ret * ret * a;
	}
}

long long ret;

long long pow_rec2(int a, long long b) {

	if (b == 1)
		return a;

	if (b % 2 == 0) {
		ret = pow_rec2(a, b / 2);
		return ret*ret;
	}
	else {
		ret = pow_rec2(a, (b - 1) / 2);
		return ret * ret * a;
	}
}

int main() {
	int start;
	start = clock();
	cout << pow_full1(10, 20) << endl;
	//cout<<(clock() - start)/1000000.0<<endl;
	cout << (clock() - start) << endl;
	start = clock();
	cout << pow_full2(2, 10) << endl;
	//cout<<(clock() - start)/1000000.0<<endl;
	cout << (clock() - start) << endl;
	start = clock();
	cout << pow_rec1(2, 50000000) << endl;
	//cout<<(clock() - start)/1000000.0<<endl;
	cout << (clock() - start) << endl;
	start = clock();
	cout << pow_rec2(2, 5000000000) << endl;
	//cout<<(clock() - start)/1000000.0<<endl;
	cout << (clock() - start) << endl;
	start = clock();
	for (int i = 0; i<100000000; i++, 10000000 << 10);
	cout << (clock() - start) << endl;
	start = clock();
	for (int i = 0; i<100000000; i++, 10000000 / 1024);
	cout << (clock() - start) << endl;
	return 0;
}