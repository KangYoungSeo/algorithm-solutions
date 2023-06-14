#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;

int N, M;
int arr[MAX];
vector<int> v;
bool visited[MAX];

void func(int idx){


	//해당 인덱스의 값을 확인해봅시다.
	//인덱스가 생각한 값을 넘어섰다! 라고 했을 때, 
	if (idx == M){
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	//인덱스가 넘지 않을 경우, 먼저 방문했는지 아닌지를 확인해서
	for (int i = 0; i < v.size(); i++){

		//방문 했다면 그다음 값을 확인하러 떠나고
		if (visited[i]) continue;

		//방문 안했으면 T라고 하고 값을 arr에 넣도록 한 후에 
		visited[i] = true;
		arr[idx] = v[i];

		// 그 이후의 값을 탐색하러 간다.
		func(idx + 1);

		// 다 탐색하면 이 친구는 나가리를 하자.
		visited[i] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// input
	cin >> N >> M; 
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	// 먼저 소트를 해줍니다. 그래야 차례대로 가능할 수 있음.
	sort(v.begin(), v.end());

	//함수를 통해서 값을 도출합니다.
	func(0);

	return 0;
}