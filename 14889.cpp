#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int board[20][20];
bool teamA[20];
int write, blue;
int min;
int N;


int compute(bool TF) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (teamA[i] == TF) {
			for (int j = i+1; j < N; j++) {
				if (teamA[j] == TF) sum += (board[i][j]+ board[j][i]);
			}
		}
	}
	return sum;
}

	//choose team link
	//recursive function 사용
void backtracking(int num, int idx) {
	
	if (idx > N) return;
	if (idx == N/2 && num == N/2) {
		for (int i = N / 2; i < N; i++) teamA[i] = true;
		backtracking(0, idx+1);
	}
	
	//compute total & compare
	if (num == 0) {
		int link = compute(true);
		int start = compute(false);
		int dis = (link > start) ? link - start : start - link;
		if (dis < min) min = dis;
	}
	else {
		teamA[idx] = true;
		backtracking(num - 1, idx + 1);
		teamA[idx] = false;
		backtracking(num, idx + 1);
	}


}


int main() {
	//init
    min = 99999999;
	//input
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
		teamA[i] = false;
	}

	backtracking(N/2,0);

	printf("%d\n", min);
	return 0;
}
