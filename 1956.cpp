#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 401

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
    int result = 9999999;

    // 인덱스 방향 a->b 로 일방통행
    int board[MAX][MAX];

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            board[i][j] = 9999999;
        }
    }

	for (int i = 0; i < E; i++) {
		int a,b,c; cin >> a >> b >> c;
		board[a][b] = c;
    }

    //플로이드 와샬
    for(int k = 1; k <= V; k++){ // 방문 노드
        for (int i = 1 ; i <= V; i++){ // 출발 노드
            for(int j = 1 ; j <= V; j++){ // 도착 노드
                if(board[i][j] > board[i][k] + board[k][j]){
                    board[i][j] = board[i][k] + board[k][j];
                    if (i == j) // 자기에게 돌아오는 길
						result = min(result, board[i][j]);
                }  
            }
        }
    }

    cout << ((result == 9999999) ? -1 : result);

	return 0;
}
