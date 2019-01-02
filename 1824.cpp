/* reference: http://ddoublej.tistory.com/290 */
#include <iostream>

using namespace std;

int x, y;
bool out, tout;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int px, py;
int count, d;
int t, ix, r, c;
char input[21][21];
int visited[21][21];

void dfs(int m, int d, int x, int y) {
	if (count++ > 3000) {
		tout = true;
		count--;
		return;
	}
	else if (visited[x][y]++ > 500) {
		tout = true;
		count--;
		return;
	}
	else if (out)
		return;
	if (input[x][y] == '?') {
		for (int i = 0; i < 4; i++) {
			d = i;
			px = x + dx[d];
			if (px == r + 1)
				px = 1;
			else if (px == 0)
				px = r;

			py = y + dy[d];
			if (py == c + 1)
				py = 1;
			else if (py == 0)
				py = c;
			dfs(m, d, px, py);
		}
	}
	else {
		if (input[x][y] >= '0' && input[x][y] <= '9')
			m = input[x][y] - '0';
		else {
			switch (input[x][y]) {
			case '<':
				d = 3;
				break;
			case '>':
				d = 1;
				break;
			case '^':
				d = 2;
				break;
			case 'v':
				d = 0;
				break;
			case '_':
				if (!m)
					d = 1;
				else
					d = 3;
				break;
			case '|':
				if (!m)
					d = 0;
				else
					d = 2;
				break;
			case '@':
				out = true;
				return;
			case '+':
				if (m == 15)
					m = 0;
				else m++;
				break;
			case '-':
				if (m == 0)
					m = 15;
				else
					m--;
				break;
			}
		}
		x += dx[d];
		if (x == r + 1)
			x = 1;
		else if (x == 0)
			x = r;

		y += dy[d];
		if (y == c + 1)
			y = 1;
		else if (y == 0)
			y = c;
		dfs(m, d, x, y);
	}
	count--;
}

int main() {
	cin >> t;
	while (t--) {
		ix++;
		cin >> r >> c;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> input[i][j];
				visited[i][j] = 0;
			}
		}
		out = tout = false;
		count = 0;

		while (true) {
			dfs(0, 1, 1, 1);

			if (out || tout)
				break;
		}

		if (!out)
			cout << '#' << ix << ' ' << "NO" << endl;
		else
			cout << '#' << ix << ' ' << "YES" << endl;
	}
	return 0;
}