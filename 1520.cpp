#include <iostream>
using namespace std;

int m, n;
int map[501][501];
int way[501][501];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool Out(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return true;
    return false;
}

int DFS(int x, int y){
    
    if(x == n-1 && y == m-1) return 1;

    if(way[x][y] != -1)return way[x][y];
        
    way[x][y] = 0;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(!Out(nx, ny) && map[nx][ny] < map[x][y]) 
            way[x][y] += DFS(nx, ny);
    }
    return way[x][y];
}

int main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            way[i][j] = -1;
        }
    }
    cout << DFS(0, 0) << '\n';
}

/*
#include <iostream>

using namespace std;

int M, N;
int board[501][501];

int sum[501][501];

int Min;
int cnt;

int total;

void input(){
    
    cin >> M >> N;
    
    for(int i = 0; i < M; i++){
        
        cin >> board[i][0];
        sum[i][0] = board[i][0];
        
        for(int j = 1; j < N; j++){
            
            cin >> board[i][j];
            
            sum[i][j] = sum[i][j-1] + board[i][j];
        }
    }
}


/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10


1.

(50) 45 37 32 30
 35  50 40 20 25
 30  30 25 17 28
 27  24 22 15 10
 
 1) 50 + 35 + 30 + 27 + 24 + 22 + 15 + 10 = 110 + 73 = 183
 
 

각 M 줄에서 순서 선택하기 => 순열을 구현하자.
순열, 조합은 사실 BFS or DFS다 이걸 공부해보자

일단 1번 줄에서는 무조건 첫번째 아이들 선택할 수 밖에 없음


조합 구하기 (DFS) + 구간합

*/

/*
void DFS(int xIdx, int yIdx, int total){
    
    //마지막 바닥 도착 시
    if(yIdx == M - 1){              //엣지 케이스 조심하기 => 이미 내려간 값은 추가 안하기
    
        for(int i = xIdx ; i < N; i++)
            total += board[M-1][i];   //오른쪽 끝까지 가기 위해 추가
        
        cout << total << endl;
        
        //최종 값을 계산 후에 해당 값이 최솟값일지 확인
        if(total < Min){            // 기존에 계산한 값보다 최소일 때
            
            cout << "변경" << endl;
            cnt = 1;                // 카운팅 초기화 
            Min = total;            // 최솟값 계산
        }
        else if (total == Min) cnt++; // 같을 경우, 카운팅
    }
    
    else{
        
        for(int i = 0; i < N; i++){                 //i : 아래 내려갈 인덱스 
        
            int add = total + board[yIdx][xIdx];    //해당 인덱스를 먼저 추가
        
            if( i < xIdx){                          // 기존 인덱스보다 적은 값으로 이동 시
        
                add += sum[yIdx][xIdx];
    
                if(i != 0) add -= sum[yIdx][i-1];
            }
        
            else if ( i > xIdx){                    // 기존 인덱스보다 큰 값으로 이동 시
            
                add += sum[yIdx][i];
            
                if(xIdx != 0) add -= sum[yIdx][xIdx];
            }
        
            DFS(i, yIdx + 1, add);
        }
    }
}


int main(){
    
    
    input();
    
    cnt = 0; Min = 100000009;
    
    int first = 0;
    
    for(int i = 0; i < N; i++){

        first += board[0][i];
        
        DFS(i, 1, total);   
    }
    
    cout << cnt << endl;
    
    return 0;
}


*/