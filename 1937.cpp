// 욕심쟁이 판다 - 구현

#include <iostream>
#include <algorithm>

using namespace std;

int N, result;

int board[501][501];
long long score[501][501];

// 상, 하, 좌, 우 중 한 곳으로 이동
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int DFS(int x, int y){
    
    if(score[x][y] == 0){
        score[x][y] =1;
        
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                
                if(board[nx][ny] > board[x][y]){
                    
                    cnt = max(cnt, DFS(nx,ny));
                
                }
            }
        }
        score[x][y] += cnt;
    }
    
    return score[x][y];
}

int main(){
    
    //n × n의 크기의 대나무 숲
    //대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야함
    
    // 어떤 지점에 처음에 풀어 놓아야 하고, 어떤 곳으로 이동을 시켜야 판다가 최대한 많은 칸을 방문할 수 있는지
    // 이 판다가 최대한 많은 칸을 이동하려면 어떤 경로를 통하여 움직여야 하는지
    cin >> N;
    result = -1;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp = DFS(i,j);
            
            if(temp > result) result = temp;
        }
    }
    
    cout << result << endl;

    return 0;
}
