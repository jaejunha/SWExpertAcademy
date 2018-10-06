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
		/* �������� �����̸� */
		if (((1 << i) & d) && v[i].r) {

			v[i].r = v[i].r - 1;

			/* �� ������ ��� ����� �� ���� */
			if (!v[i].r)
				u[v[i].i].d = u[v[i].i].d - 1;
		}
	}

	for (int i = 0; i < l; i++) {

		/* �տ��� �����Ѱ� �ǳ� ���� */
		if ((1 << i) & d)
			continue;

		/* ��ܿ��� ��Ⱑ ���� ��� */
		if ((1 << i) & w) {
			if (u[v[i].i].d < 3) {
				d = (d | (1 << i));
				u[v[i].i].d = u[v[i].i].d + 1;
				u[v[i].i].w = u[v[i].i].w - 1;
			}
		}
		/* ����ڰ� ��ܿ� �ִ� ��� */
		else if (u[v[i].i].x == v[i].x && u[v[i].i].y == v[i].y)
			w = (w | (1 << i));
		/*��� ������ ���*/
		else if (abs(u[v[i].i].x - v[i].x) + abs(u[v[i].i].y - v[i].y) == 1) {
			if (u[v[i].i].w < 3) {
				u[v[i].i].w = u[v[i].i].w + 1;
				v[i].x = u[v[i].i].x;
				v[i].y = u[v[i].i].y;
			}
		}
		/* ����ڰ� ��ܿ� ���� �ʴ� ��� */
		else {
			/* ��� x��ġ�� ������ ��� */
			if (u[v[i].i].x == v[i].x) {
				/* y�� �̵� */
				if (u[v[i].i].y > v[i].y)
					v[i].y = v[i].y + 1;
				else
					v[i].y = v[i].y - 1;
			}
			/* ��� x��ġ�� �������� ���� ��� */
			else {
				/* x�� �̵� */
				if (u[v[i].i].x > v[i].x)
					v[i].x = v[i].x + 1;
				else
					v[i].x = v[i].x - 1;
			}
		}
	}

	/* ��� �� ���� ������ üũ*/
	int c = 0;

	/* �� ������ �������� Ȯ�� */
	for (int i = 0; i < l; i++) {
		if (!v[i].r)
			c++;
	}

	/* �̹� �� ������ ���¸� ���� */
	if (c == l) {
		s = min(s, time);
		return;
	}

	sim(time + 1, w, d);
}

void dfs(int ix) {
	/* �� ����ڿ��� ��� �� �Ҵ� �ϸ� */
	if (ix == l) {
		u[0].w = u[1].w = 0;
		u[0].d = u[1].d = 0;
		v = o;
		sim(0, 0, 0);
		return;
	}
	else {
		/* 0�� ��� �Ҵ� */
		o[ix].i = 0;
		o[ix].r = a[u[0].x][u[0].y];
		dfs(ix + 1);

		/* 1�� ��� �Ҵ� */
		o[ix].i = 1;
		o[ix].r = a[u[1].x][u[1].y];
		dfs(ix + 1);
	}
}

int main() {
	cin >> t;
	for (int z = 1; z <= t; z++) {
		/* �Է� */
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

		/* ��� */
		cout << '#' << z << ' ' << s << endl;
	}
	return 0;
}