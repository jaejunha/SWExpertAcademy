#include <iostream>
#include <queue>

using namespace std;

typedef struct P {
	int x;
	int y;
}P;

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

int no;
int t, n, a[101][101];
int d[101][101];

int x, y, c, px, py;
P p;

int main() {
	cin >> t;
	while (t--) {
		no++;
		cin >> n;

		/* Init */
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%1d", &a[i][j]);
				d[i][j] = 100000;
			}
		}

		queue<P> q;
		p.x = p.y = 1;
		d[1][1] = 0;
		q.push(p);
		while (!q.empty()) {
			x = q.front().x;
			y = q.front().y;
			q.pop();
			if (x == n && y == n)
				continue;
			for (int i = 0; i<4; i++) {
				px = x + dx[i];
				py = y + dy[i];
				if (px > n || py > n || px < 1 || py < 1)
					continue;
				if (d[px][py]>d[x][y] + a[px][py]) {
					d[px][py] = d[x][y] + a[px][py];
					p.x = px;
					p.y = py;
					q.push(p);
				}
			}
		}

		cout << "#" << no << " " << d[n][n] << endl;
	}
	return 0;
}