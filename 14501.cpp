/*
	2021 - 03 - 20 <brute-force>
	beakjun 14501
	KangYoungSeo

	반복문 2개 => O(N^2)
*/
#include <iostream>
using namespace std;

int time[16];
int pay[16];
int N;

int recursive(int idx) {

	if(idx > N) return 0;
	int FF = recursive(idx + 1);

	if (idx + time[idx] > N + 1) return FF;
	
	int TT = pay[idx] + recursive(idx + time[idx]);
	return TT > FF ? TT : FF;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &time[i], &pay[i]);

	//using recursive function, search all of cases, and find max

	int max = recursive(1);
	printf("%d", max);
	return 0;
}