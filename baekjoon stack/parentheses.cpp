#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int N; cin >> N;
	vector<char> temp;
	int Cnt = 0;
	while (N-- > 0) {
		string str; cin >> str;
		bool VPS = false;
		int i;
		for (i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				temp.push_back('(');
			}
			else if (str[i] == ')') {
				if (temp.size() == 0) break;
				else temp.pop_back();
			}
		}
		if (temp.size() == 0&& i == str.size()) cout << "YES" << endl;
		else cout << "NO" << endl;
		temp.clear();
	}
	return 0;
}