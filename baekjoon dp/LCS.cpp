#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//첫째 줄과 둘째 줄에 두 문자열이 주어진다. 
	//문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
	string str1, str2;  cin >> str1 >> str2;
	int M = str1.size();
	int N = str2.size();

	vector<vector<int>> dp(M+1);
	for (int i = 0; i < M + 1; i++) dp[i].resize(N + 1, 0);

	//비교 진행하기
	for (int i = 0; i < M ; i++){
		for (int j = 0; j < N ; j++) {

			//같을 경우
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;

			//다를 경우
			else dp[i + 1][j + 1] = dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j];

        }
	}

	cout << dp[M][N] << endl;
	return 0;
}