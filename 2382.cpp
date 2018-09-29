#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

typedef struct A {
	int x, y, c, d;
}A;

int n, m, k, t;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool b[100][100];

int main() {
	int m;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		cin >> n >> m >> k;
		int x, y, c, d;
		vector<A> v;
		A a;
		for (int i = 1; i <= k; i++) {
			cin >> x >> y >> c >> d;
			a.x = x;
			a.y = y;
			a.c = c;
			a.d = d;
			v.push_back(a);
		}
		int l = v.size();
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++)
					b[j][k] = false;
			}

			/* 세균들이 합치는 것 고려할 집합 */
			set<pair<int, int>> st;

			for (int j = 0; j < l; j++) {
				if (!v[j].c)
					continue;
				int px = v[j].x + dx[v[j].d - 1];
				int py = v[j].y + dy[v[j].d - 1];

				v[j].x = px;
				v[j].y = py;

				/* 벽에 닿은 경우 */
				if (px == 0 || py == 0 || px == n - 1 || py == n - 1) {
					v[j].c = v[j].c / 2;
					if (!v[j].c)
						continue;
					if (v[j].d == 1)
						v[j].d = 2;
					else if (v[j].d == 2)
						v[j].d = 1;
					else if (v[j].d == 3)
						v[j].d = 4;
					else
						v[j].d = 3;
				}

				/* 옮긴 자리에 이미 세균이 있는 경우 */
				if (b[px][py])
					st.insert({ px,py });
				b[px][py] = true;
			}
			for (pair<int, int> p : st) {
				int mx = -1;
				int s = 0;
				for (int k = 0; k < l; k++) {
					if (v[k].x == p.first && v[k].y == p.second) {
						if (mx == -1) {
							mx = k;
							s += v[k].c;
						}
						else {
							if (v[mx].c < v[k].c) {
								v[mx].c = 0;
								mx = k;
								s += v[k].c;
							}
							else {
								s += v[k].c;
								v[k].c = 0;
							}
						}
					}
				}
				v[mx].c = s;
			}
		}
		int s = 0;
		for (A a : v)
			s += a.c;
		cout << '#' << z << ' ' << s << endl;
	}
	return 0;
}