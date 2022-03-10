#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N; cin >> N; if (N < 2 || N > 50) return 0;
	vector<int> high = {};
	vector<int> weight = {};
	int* rank = new int[N]; for (int i = 0; i < N; i++) rank[i] = 1;

	for (int i = 0; i < N; i++) {
		int x; cin >> x; if (x < 10 || x >200) return 0;
		int y; cin >> y; if (y < 10 || y >200) return 0;

		weight.push_back(x); high.push_back(y);
	}

	for(int i = 0; i< N; i++){							
		for (int j = 0; j < N; j++) {	
				
			if (i == j) continue;
			if ((high[i] < high[j]) && (weight[i] < weight[j])) 
					rank[i]++;
		}
	}
  
	for (int i = 0; i < N; i++)
		cout << rank[i]<<" ";
  
	return 0;
}
