#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int t;
int n, l, s[144];
vector<P> v;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int a[][12], int x, int o) {
	if (x == l) {
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 2)
					c++;
			}
		}
		s[o - 1] = min(s[o - 1], c);
		return;
	}

	int b[12][12];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[i][j] = a[i][j];
	for (int i = 0; i < 4; i++) {
		int px = v[x].first + dx[i];
		int py = v[x].second + dy[i];
		if (b[px][py])  //선이나 core가 있는 경우
			continue;

		int qx = px;
		int qy = py;
		while (1) {
			if (b[qx][qy])
				break;
			if (qx == 0 || qy == 0 || qx == n - 1 || qy == n - 1)
				break;
			qx += dx[i];
			qy += dy[i];
		}
		if (b[qx][qy])
			continue;
		if (qx > 0 && qy > 0 && qx < n - 1 && qy < n - 1)
			continue;

		if (i == 1 || i == 2) {
			for (int j = px; j <= qx; j++) {
				for (int k = py; k <= qy; k++)
					b[j][k] = 2;
			}
		}
		else {
			for (int j = px; j >= qx; j--) {
				for (int k = py; k >= qy; k--)
					b[j][k] = 2;
			}
		}
		dfs(b, x + 1, o + 1);
		if (i == 1 || i == 2) {
			for (int j = px; j <= qx; j++) {
				for (int k = py; k <= qy; k++)
					b[j][k] = 0;
			}
		}
		else {
			for (int j = px; j >= qx; j--) {
				for (int k = py; k >= qy; k--)
					b[j][k] = 0;
			}
		}
	}
	dfs(b, x + 1, o);
}

int main() {
	int a[12][12];
	scanf("%d", &t);
	for (int k = 1; k <= t; k++) {
		scanf("%d", &n);
		v.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				if (a[i][j]) {
					if (!(i == 0 || i == n - 1 || j == 0 || j == n - 1)) {
						v.push_back({ i,j });
					}
				}
			}
		}
		l = v.size();
		for (int i = 0; i < l; i++)
			s[i] = n * n;
		dfs(a, 0, 0);
		for (int i = l - 1, m = n * n; i >= 0; i--) {
			if (s[i] != m) {
				printf("#%d %d\n", k, s[i]);
				break;
			}
			if (i == 0 && s[i] == m)
				printf("#%d %d", k, 0);
		}
	}
	return 0;
}