#include <iostream>
using namespace std;
int main()
{
	int C; cin >> C;
	while (C-- > 0) {
		int N; cin >> N;
		int* score = new int[N];
		double result = 0;
		for (int i = 0; i < N; i++) {
			cin >> score[i]; result += score[i];
		}
		result = result / N;
		int Cnt = 0;
		for (int i = 0; i < N; i++) {
			if (result < score[i]) 	Cnt++;
		}
		double Get = ((double)Cnt / N) * 100;
		printf("%.3lf", Get); cout << '%' << endl;}
	return 0;}
