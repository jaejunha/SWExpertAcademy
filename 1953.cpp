#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t, n, m, r, c, l;
int a[50][50];
bool b[50][50];
int px, py;

int main() {

	cin >> t;
	for (int z = 1; z <= t; z++) {
		/* �Է� �� �ʱ�ȭ */
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				b[i][j] = false;
			}
		}

		/* ��Ȧ ��ġ ť�� ���� */
		queue<pair<int, int>> q;
		q.push({ r,c });
		int s = 1;
		while (l--) {
			for (int i = 0; i < s; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (b[x][y])
					continue;
				b[x][y] = true;
				switch (a[x][y]) {
				case 1:
					/* �� */
					px = x - 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 5 || a[px][py] == 6))
						q.push({ px, py });

					/* �� */
					px = x + 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 4 || a[px][py] == 7))
						q.push({ px, py });

					/* �� */
					px = x;
					py = y - 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 4 || a[px][py] == 5))
						q.push({ px, py });

					/* �� */
					px = x;
					py = y + 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 6 || a[px][py] == 7))
						q.push({ px, py });
					break;
				case 2:
					/* �� */
					px = x - 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 5 || a[px][py] == 6))
						q.push({ px, py });

					/* �� */
					px = x + 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 4 || a[px][py] == 7))
						q.push({ px, py });
					break;
				case 3:
					/* �� */
					px = x;
					py = y - 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 4 || a[px][py] == 5))
						q.push({ px, py });

					/* �� */
					px = x;
					py = y + 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 6 || a[px][py] == 7))
						q.push({ px, py });
					break;
				case 4:
					/* �� */
					px = x - 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 5 || a[px][py] == 6))
						q.push({ px, py });

					/* �� */
					px = x;
					py = y + 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 6 || a[px][py] == 7))
						q.push({ px, py });
					break;
				case 5:
					/* �� */
					px = x + 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 4 || a[px][py] == 7))
						q.push({ px, py });

					/* �� */
					px = x;
					py = y + 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 6 || a[px][py] == 7))
						q.push({ px, py });
					break;
				case 6:
					/* �� */
					px = x + 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 4 || a[px][py] == 7))
						q.push({ px, py });

					/* �� */
					px = x;
					py = y - 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 4 || a[px][py] == 5))
						q.push({ px, py });
					break;
				case 7:
					/* �� */
					px = x - 1;
					py = y;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 2 || a[px][py] == 5 || a[px][py] == 6))
						q.push({ px, py });

					/* �� */
					px = x;
					py = y - 1;
					if (!b[px][py] && (a[px][py] == 1 || a[px][py] == 3 || a[px][py] == 4 || a[px][py] == 5))
						q.push({ px, py });
					break;
				}
			}
			s = q.size();
		}
		int sol = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (b[i][j])
					sol++;
		cout << "#" << z << ' ' << sol << endl;
	}
	return 0;
}