#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S; cin >> S;
	vector<int> dp[26];

	for (int i = 0; i < S.size(); ++i) {
		for (int j = 0; j < 26; ++j) {
			if (i == 0) {
				int num = S[i] - 'a';
				if (num == j) {
					dp[j].push_back(1);
				}
				else {
					dp[j].push_back(0);
				}
			}
			else {
				int num = S[i] - 'a';
				if (num == j) {
					dp[j].push_back(dp[j][i - 1] + 1);
				}
				else {
					dp[j].push_back(dp[j][i - 1]);
				}
			}
		}
	}
	int q, l, r;
	char alphabet;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> alphabet >> l >> r;
		int idx = alphabet - 'a';
		if (l == 0) {
			cout << dp[idx][r] << "\n";
		}
		else {
			cout << dp[idx][r] - dp[idx][l - 1] << "\n";
		}
	}
	

	return 0;
}
