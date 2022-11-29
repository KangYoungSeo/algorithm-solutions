#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//in & out fast
void fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	fast_io();

	//input
	int V, E; cin >> V >> E;

    // 인덱스 방향 a->b 로 일방통행
    vector<int> board[400];
    bool visited[400];

	for (int i = 0; i < E; i++) {
		int a,b,c; cin >> a >> b >> c;
		board[a][b] = c;
	}



    for(int i = 0; i < V; i++){
        if(visited[i] == true) continue;



    }


	return 0;
}
