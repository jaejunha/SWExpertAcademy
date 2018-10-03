#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef struct {
	int x, y, i, r;
}O;
typedef struct {
	int x, y, w;
}P;

int n, t, s, l;

int a[11][11];
vector<O> o, v;
vector<P> u;
O temp_o;
P temp_p;

void sim(int time, int bit) {

	int d[2] = { 0,0 };
	int b = bit;
	/* 계단 다 내려 갔는지 체크*/
	int c = 0;

	for (int i = 0; i < l; i++) {
		/* 계단을 다 내려간 경우 */
		if (!v[i].r) {
			c++;
			continue;
		}
		/* 사용자가 계단에 있는 경우 */
		if (u[v[i].i].x == v[i].x && u[v[i].i].y == v[i].y) {
			/* 대기 시간 1초가 지난 경우 */
			if ((1 << i) & b) {
				v[i].r = v[i].r - 1;

				/* 다 내려간 경우 대기자 수 감소 */
				if (!v[i].r)
					d[v[i].i]++;
			}
			/* 대기 시간 1초가 지나지 않은 경우 */
			else
				b = b | 1 << i;
		}
		/* 사용자가 계단에 있지 않는 경우 */
		else {
			/* 계단 직전에 온 경우 */
			if (abs(u[v[i].i].x - v[i].x) + abs(u[v[i].i].y - v[i].y) == 1) {

				/* 이미 4명이 계단에 있으면 다음 기회에... */
				if (u[v[i].i].w == 4)
					continue;

				/* 계단 위치로 */
				v[i].x = u[v[i].i].x;
				v[i].y = u[v[i].i].y;
				u[v[i].i].w = u[v[i].i].w + 1;
			}
			else {
				/* 계단 x위치에 도달한 경우 */
				if (u[v[i].i].x == v[i].x) {
					/* y축 이동 */
					if (u[v[i].i].y > v[i].y)
						v[i].y = v[i].y + 1;
					else
						v[i].y = v[i].y - 1;
				}
				/* 계단 x위치에 도달하지 못한 경우 */
				else {
					/* x축 이동 */
					if (u[v[i].i].x > v[i].x)
						v[i].x = v[i].x + 1;
					else
						v[i].x = v[i].x - 1;
				}
			}
		}
	}
	u[0].w -= d[0];
	u[1].w -= d[1];

	if (c == l) {
		s = min(s, time);
		return;
	}

	sim(time + 1, b);
}

void dfs(int ix) {
	/* 각 사용자에게 계단 다 할당 하면 */
	if (ix == l) {
		u[0].w = u[1].w = 0;
		v = o;
		sim(0, 0);
		return;
	}
	else {
		/* 0번 계단 할당 */
		o[ix].i = 0;
		o[ix].r = a[u[0].x][u[0].y];
		dfs(ix + 1);

		/* 1번 계단 할당 */
		o[ix].i = 1;
		o[ix].r = a[u[1].x][u[1].y];
		dfs(ix + 1);
	}
}

int main() {
	cin >> t;
	for (int z = 1; z <= t; z++) {
		/* 입력 */
		cin >> n;
		o.clear();
		u.clear();
		s = 999999;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j]) {
					if (a[i][j] == 1) {
						temp_o.x = i;
						temp_o.y = j;
						o.push_back(temp_o);
					}
					else {
						temp_p.x = i;
						temp_p.y = j;
						temp_p.w = 0;
						u.push_back(temp_p);
					}
				}
			}
		}
		l = o.size();

		/* dfs */
		dfs(0);

		/* 출력 */
		cout << '#' << z << ' ' << s << endl;
	}
	return 0;
}