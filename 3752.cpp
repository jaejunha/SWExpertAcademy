/* reference: http://his130.tistory.com/298 */
#include <iostream>

using namespace std;

int main() {
	int t, no = 0, n, x[101], max, sol;
	bool v[10001];
	v[0] = true;
	cin >> t;
	while (t--) {
		no++;
		cin >> n;
		max = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			max += x[i];
		}
		for (int i = 1; i <= max; i++)
			v[i] = false;
		for (int i = 1; i <= n; i++) {
			for (int j = max; j >= 0; j--) {
				if (v[j])
					v[j + x[i]] = true;
			}
		}

		sol = 0;
		for (int i = 0; i <= max; i++)
			if (v[i])
				sol++;

		cout << "#" << no << " " << sol << endl;
	}
	return 0;
}