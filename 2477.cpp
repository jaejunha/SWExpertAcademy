/* reference: http://2youngjae.tistory.com/96 */
#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int n, m, d;
}U;

int T, N, M, K, A, B;
int a[11], b[11], t[1001];
int v_a[11], v_b[11];
U u[1001];

int main() {

	cin >> T;
	for (int z = 1; z <= T; z++) {
		/* �Է� �� �ʱ�ȭ */
		cin >> N >> M >> K >> A >> B;
		int n = 0, m = 0;
		for (int i = 1; i <= N; i++) {
			v_a[i] = 0;
			cin >> a[i];
		}
		for (int i = 1; i <= M; i++) {
			v_b[i] = 0;
			cin >> b[i];
		}
		for (int i = 1; i <= K; i++)
			cin >> t[i];

		int time = 0;
		int check = 0;
		/* ���� ��� */
		queue<int> qw, qa, qb;
		for (int i = 1; i <= K; i++)
			qw.push(i);

		for (; 1; time++) {
			/* ������ �� ������������ üũ */
			if (check == K)
				break;

			/* ��� ���� Ȯ�� */
			while (!qw.empty()) {
				if (time < t[qw.front()])
					break;
				qa.push(qw.front());
				qw.pop();
			}

			/* ��� -> ���� */
			for (int i = 1; (i <= N) && (n < N) && !qa.empty(); i++) {
				if (!v_a[i]) {
					u[qa.front()].n = i;
					u[qa.front()].d = a[i];
					v_a[i] = qa.front();
					n++;
					qa.pop();
				}
			}

			/* ���� -> ���� */
			for (int i = 1; (i <= M) && (m < M) && !qb.empty(); i++) {
				if (!v_b[i]) {
					u[qb.front()].m = i;
					u[qb.front()].d = b[i];
					v_b[i] = qb.front();
					m++;
					qb.pop();
				}
			}

			/* ���� ���� ���� */
			for (int i = 1; i <= N; i++) {
				if (v_a[i]) {
					u[v_a[i]].d--;
					if (u[v_a[i]].d == 0) {
						qb.push(v_a[i]);
						v_a[i] = 0;
						n--;
					}
				}
			}

			/* ���� ���� ���� */
			for (int i = 1; i <= M; i++) {
				if (v_b[i]) {
					u[v_b[i]].d--;
					if (u[v_b[i]].d == 0) {
						check++;
						v_b[u[v_b[i]].m] = 0;
						m--;
					}
				}
			}
		}

		int sol = 0;
		for (int i = 1; i <= K; i++) {
			if (u[i].n == A && u[i].m == B)
				sol += i;
		}
		cout << "#" << z << ' ' << ((!sol) ? -1 : sol) << endl;
	}
	return 0;
}