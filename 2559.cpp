#include <iostream>
#include <vector>
using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K; 
	cin >> N >> K;
	vector<int> dp(N + 1);

	int num; cin >> num;
	dp[0] = num;

	for (int i = 1; i < N; i++) {
		int num; cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	int max = dp[K-1];

	for (int i = 0; i < N - K ; i++) {

		int sum = dp[i + K] - dp[i];
		if (sum > max) max = sum;

	}

	cout << max << '\n';
	

	return 0;
}
