#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int n, m, d, s;
}U;

int T, N, M, K, A, B;
int a[11], b[11], t[1001];
bool v_a[11], v_b[11];
U u[1001];

int main() {

	cin >> T;
	for (int z = 1; z <= T; z++) {
		/* 입력 및 초기화 */
		cin >> N >> M >> K >> A >> B;
		int n = 0, m = 0;
		for (int i = 1; i <= N; i++) {
			v_a[i] = false;
			cin >> a[i];
		}
		for (int i = 1; i <= M; i++) {
			v_b[i] = false;
			cin >> b[i];
		}
		for (int i = 1; i <= K; i++) {
			u[i].s = 0;
			cin >> t[i];
		}

		int time = 0;
		while (true) {

			/* 고객들이 다 빠져나갔는지 체크 */
			int check = 0;
			for (int i = 1; i <= K; i++) {
				if (u[i].s == 3)
					check++;
			}
			if (check == K)
				break;

			/* 정비 상태 확인 */
			for (int i = 1; i <= K; i++) {
				if (u[i].s == 2) {
					if (u[i].d > 0) {
						u[i].d--;
						if (!u[i].d) {
							u[i].s = 3;
							v_b[u[i].m] = false;
							m--;
						}
					}
					else {
						u[i].s = 3;
						v_b[u[i].m] = false;
						m--;
					}
				}
			}

			/* 접수 상태 확인 */
			for (int i = 1; i <= K; i++) {
				if (u[i].s == 1) {
					if (u[i].d > 0) {
						u[i].d--;
						if (!u[i].d && m < M) {
							u[i].s = 2;
							v_a[u[i].n] = false;
							n--;
							for (int j = 1; j <= M; j++) {
								if (!v_b[j]) {
									u[i].m = j;
									u[i].d = b[j];
									v_b[j] = true;
									break;
								}
							}
							m++;
						}
					}
					else {
						if (m < M) {
							u[i].s = 2;
							v_a[u[i].n] = false;
							n--;
							for (int j = 1; j <= M; j++) {
								if (!v_b[j]) {
									u[i].m = j;
									u[i].d = b[j];
									v_b[j] = true;
									break;
								}
							}
							m++;
						}
					}
				}
			}

			/* 대기 상태 확인 */
			for (int i = 1; i <= K; i++) {
				if (u[i].s == 0 && time >= t[i]) {
					if (n < N) {
						u[i].s = 1;
						for (int j = 1; j <= N; j++) {
							if (!v_a[j]) {
								u[i].n = j;
								u[i].d = a[j];
								v_a[j] = true;
								break;
							}
						}
						n++;
					}
				}
			}
			time++;
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