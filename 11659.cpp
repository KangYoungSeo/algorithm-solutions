#include <iostream>
#include <vector>
using namespace std;

void fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main() {


	fast_io();
	int N, M; cin >> N >> M;
	vector<long> dp(N + 1);
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		long num; cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	int sum = 0; 

	while(M --> 0){
		int i, j; cin >> i >> j;

		cout << dp[j] - dp[i-1] << endl;
	}

	return 0;
}
