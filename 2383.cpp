#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef struct {
	int x, y, i, r;
}O;
typedef struct {
	int x, y, w, d;
}P;

int n, t, s, l;

int a[11][11];
vector<O> o, v;
vector<P> u;
O temp_o;
P temp_p;

void sim(int time, int wait, int down) {

	int w = wait;
	int d = down;

	for (int i = 0; i < l; i++) {
		/* 내려가는 상태이면 */
		if (((1 << i) & d) && v[i].r) {

			v[i].r = v[i].r - 1;

			/* 다 내려간 경우 대기자 수 감소 */
			if (!v[i].r)
				u[v[i].i].d = u[v[i].i].d - 1;
		}
	}

	for (int i = 0; i < l; i++) {

		/* 앞에서 조사한건 건너 뛰자 */
		if ((1 << i) & d)
			continue;

		/* 계단에서 대기가 끝난 경우 */
		if ((1 << i) & w) {
			if (u[v[i].i].d < 3) {
				d = (d | (1 << i));
				u[v[i].i].d = u[v[i].i].d + 1;
				u[v[i].i].w = u[v[i].i].w - 1;
			}
		}
		/* 사용자가 계단에 있는 경우 */
		else if (u[v[i].i].x == v[i].x && u[v[i].i].y == v[i].y)
			w = (w | (1 << i));
		/*계단 직전인 경우*/
		else if (abs(u[v[i].i].x - v[i].x) + abs(u[v[i].i].y - v[i].y) == 1) {
			if (u[v[i].i].w < 3) {
				u[v[i].i].w = u[v[i].i].w + 1;
				v[i].x = u[v[i].i].x;
				v[i].y = u[v[i].i].y;
			}
		}
		/* 사용자가 계단에 있지 않는 경우 */
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

	/* 계단 다 내려 갔는지 체크*/
	int c = 0;

	/* 다 내려간 상태인지 확인 */
	for (int i = 0; i < l; i++) {
		if (!v[i].r)
			c++;
	}

	/* 이미 다 내려간 상태면 종료 */
	if (c == l) {
		s = min(s, time);
		return;
	}

	sim(time + 1, w, d);
}

void dfs(int ix) {
	/* 각 사용자에게 계단 다 할당 하면 */
	if (ix == l) {
		u[0].w = u[1].w = 0;
		u[0].d = u[1].d = 0;
		v = o;
		sim(0, 0, 0);
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