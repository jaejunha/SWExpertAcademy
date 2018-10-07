#include <iostream>
#include <algorithm>
using namespace std;

int t;
int c[4];
int a[12];
int s;

void dfs(int index, int cost) {
	/* 12월을 넘기는 경우 */
	if (index >= 12) {
		s = min(s, cost);
		return;
	}

	dfs(index + 1, cost + a[index] * c[0]);
	dfs(index + 1, cost + (a[index] ? 1 : 0)*c[1]);
	dfs(index + 3, cost + c[2]);
	dfs(index + 12, cost + c[3]);
}

int main() {

	cin >> t;
	for (int z = 1; z <= t; z++) {
		for (int i = 0; i < 4; i++)
			cin >> c[i];
		s = 999999;
		for (int i = 0; i < 12; i++)
			cin >> a[i];
		dfs(0, 0);
		cout << "#" << z << ' ' << s << endl;
	}
	return 0;
}