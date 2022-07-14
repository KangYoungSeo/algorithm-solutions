#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int main()
{
	int T; cin >> T;
	while (T-->0) {
		int N; cin >> N;
		vector<pair<int, string>> list;
		for (int i = 0; i < N; i++) {
			string name, kind;
			cin >> name;
			cin >> kind;
			int j;
			for (j = 0; j < list.size(); j++) {
				if (list[j].second == kind) {
					list[j].first++; break;
				}
			}
			if (j == list.size()) list.push_back(make_pair(1, kind));
		}
		int result = 1;
		for (int i = 0; i < list.size(); i++) {
			result *= (list[i].first + 1);
		}
		cout << result - 1 << endl;
	}
	return 0;
}
