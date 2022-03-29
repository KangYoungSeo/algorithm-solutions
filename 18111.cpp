/*
	2021 - 03 - 20 <brute-force>
	beakjun 18111
	KangYoungSeo

	O(n^2)
	배열탐색 * 기준 탐색
*/

#include <iostream>
using namespace std;

int map[501][501];


int main() {
	int N, M, B;
	scanf("%d %d %d", &N, &M, &B);

	int max = -1;
	int min = 257;

	//땅들의 높이를 입력받는 데, 이때 최대값 최소값을 미리 구한다

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			if (max < map[i][j]) max = map[i][j];
			else if (min > map[i][j]) min = map[i][j];
		}
	}

	int high = -1;
	int minT = 9999999999;
	int time = 0;

	for (int k = min; k <= max; k++) {

		time = 0;
		int minus = 0;
		int plus = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > k) {
					//time += 2 * (map[i][j] - k);
					plus+= (map[i][j] - k);
				}
				else if (map[i][j] < k) {
					//time += (k - map[i][j]);
					minus+= (k - map[i][j]);
				}
			}
		}
		
		if ((B + plus - minus) < 0) continue;

		time = plus * 2 + minus;

		if (minT > time) {
			minT = time;
			high = k;
		}
		else if (minT == time && high < k)
			high = k;

	}

	//땅을 고르는 데 걸리는 시간 + 땅의 높이
	//답이 여러개 있다면 땅의 높이가 높은 것
	printf("%d %d", minT, high);

	return 0;
}
