#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

//문제가 자료형의 범위 문제인 것 같다

using namespace std;

int visited[300001];

int main() {

	//init---------------------------------------------------------------
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N; // 2 ≤ N ≤ 300,000 도시의 개수
	int M; cin >> M; // 1 ≤ M ≤ 1,000,000 도로의 개수
	int K; cin >> K; // 1 ≤ K ≤ 300,000 거리 정보
	int X; cin >> X; //1 ≤ X ≤ N 출발 도시의 번호

	// 연결 edge 정보저장
	vector<vector<unsigned int>> connect(N + 1);

	//도로 정보 저장
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		connect[a].push_back(b);
	}

	// output----------------------------------------------------------------
	// DFS, K 거리까지 도달했을 때 END

	queue<pair<int, int>> search;
	vector<int> result;
	search.push(make_pair(X, 0));		// X에서 시작 거리는 0 부터!

	while (!search.empty()) {

		//맨 앞의 값을 얻고 삭제!
		int node = search.front().first;
		int depth = search.front().second;
		search.pop();


		//길이가 일치하면 결과에 추가!
		if (depth == K) {
			result.push_back(node);
		}

		//해당 노드와 연결된 노드들을 서치해본다
		for (unsigned int i = 0; i < (unsigned int) connect[node].size(); i++) {
			int next_node = connect[node][i];

			//한번 방문한 적이 없다면,
			if (!visited[next_node]) {
				visited[next_node] = true;
				search.push(make_pair(next_node, depth + 1));
			}
		}
	}

	//print ----------------------------
	if (result.size() == 0) { cout << -1 << endl; return 0; }
	else {

		sort(result.begin(), result.end());
		for (auto a : result) cout << a << '\n';
	}
	
	return 0;
}
