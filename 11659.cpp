#include <iostream>
#include <vector>
using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; 
	cin >> N >> M;
	vector<long> dp(N + 1);
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		long num; cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	int sum = 0; 

	while(M --> 0){
		int i, j; 
		cin >> i >> j;

		cout << dp[j] - dp[i-1] << '\n';
	}

	return 0;
}
