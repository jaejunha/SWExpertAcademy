/* reference: http://xn--299as6vb5i1je.com/swexpert/73 */
#include <iostream>
#include <algorithm>
using namespace std;

int t, n, k, s;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool v[9][9];
int a[9][9];

void dfs(int x, int y, int c, bool b) {
	v[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int px = x + dx[i];
		int py = y + dy[i];
		if (px<1 || py<1 || px>n || py>n)
			continue;
		if (v[px][py])
			continue;
		if (a[px][py] < a[x][y])
			dfs(px, py, c + 1, b);
		else if ((a[px][py] < a[x][y] + k) && !b) {
			int temp = a[px][py];
			a[px][py] = a[x][y] - 1;
			dfs(px, py, c + 1, true);
			a[px][py] = temp;
		}
	}
	v[x][y] = false;
	s = max(s, c);
}

int main() {
	int m;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		cin >> n >> k;
		s = m = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				v[i][j] = false;
				m = max(m, a[i][j]);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == m)
					dfs(i, j, 1, false);
			}
		}
		cout << "#" << z << " " << s << endl;
	}

	return 0;
}