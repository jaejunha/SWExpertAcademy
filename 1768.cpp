/* reference: https://gonayoung.tistory.com/16 */

#define N 4

typedef struct {
	int strike;
	int ball;
} Result;

// API

extern Result query(int guess[]);

bool first = true;
int p[10000];
bool checked[10000];
int count;

Result compare(int x, int y) {
	Result result;

	result.strike = 0;
	result.ball = 0;

	int c[10] = { 0 };

	int x_d, y_d;
	for (int i = 0; i < N; i++, x /= 10, y /= 10) {
		x_d = x % 10;
		y_d = y % 10;
		if (x_d == y_d)
			result.strike++;

		c[x_d]++;
		c[y_d]++;
	}

	for (int i = 0; i < 10; i++) {
		if (c[i] > 1)
			result.ball++;
	}
	result.ball -= result.strike;

	return result;
}

void doUserImplementation(int guess[]) {
	if (first) {
		first = false;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (j == i)
					continue;
				for (int k = 0; k < 10; k++) {
					if (k == j || k == i)
						continue;
					for (int l = 0; l < 10; l++) {
						if (l == i || l == j || l == k)
							continue;
						p[count++] = 1000 * i + 100 * j + 10 * k + l;
					}
				}
			}
		}
	}

	for (int i = 0; i<count; i++)
		checked[p[i]] = false;

	Result result[2];
	for (int i = 0; i<count; i++) {
		if (checked[p[i]])
			continue;
		checked[p[i]] = true;

		guess[0] = p[i] / 1000;
		guess[1] = (p[i] % 1000) / 100;
		guess[2] = (p[i] % 100) / 10;
		guess[3] = p[i] % 10;

		result[0] = query(guess);
		if (result[0].strike == N)
			break;

		for (int j = i + 1; j < count; j++) {
			if (checked[p[j]])
				continue;
			result[1] = compare(p[i], p[j]);
			if (result[0].ball != result[1].ball || result[0].strike != result[1].strike)
				checked[p[j]] = true;
		}
	}
}
