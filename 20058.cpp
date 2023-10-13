#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int A[65][65];
int N, Q, temp;

bool Visit[65][65];

vector<int> L;
int Max, MaxMess;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct mess{
    int x;
    int y;
    int conn;
};

void debug(){
    
    for(int i = 0; i < Max; i++){
        for(int j = 0; j < Max; j++) cout << A[j][i] << " ";
        cout << endl;
    }
}

void input(){
    
    cin >> N >> Q;      //입력
    Max = pow(2,N);     //판 짜기
    
    for(int i = 0; i < Max; i++)
        for(int j = 0; j < Max; j++)
            cin >> A[j][i];
    
    for(int i = 0; i < Q; i++) {
        
        cin >> temp;
        L.push_back(temp);
    }
    
    MaxMess = 0;
    
    //debug();
}

void rotate(int L){
    
    int rotMax = pow(2,L);
    int changeA[65][65];

    for(int x = 0; x < Max; x += rotMax){
        for(int y = 0; y < Max; y += rotMax){
            
            for(int i = 0; i < rotMax; i++){            //회전 값
                for(int j = 0; j < rotMax; j++)
                    changeA[ x + rotMax - i - 1 ][y + j] = A[ x + j][y + i];
            }
        }
    }
    
    //바뀐 보드를 이전 보드에 덮기
    for(int i = 0; i < Max; i++){
        for(int j = 0; j < Max; j++){
            A[i][j] = changeA[i][j];
        }
    }
    
    //debug();
}

void reduceIce(){
    
    vector<pair<int,int>> reduce;
    
    for(int i = 0; i < Max; i++){
        for(int j = 0; j < Max; j++){
            
            int ice = 0;
            
            for(int k = 0; k < 4; k++){     //상하좌우 비교
                
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                
                if( nx >= 0 && nx < Max && ny >= 0 && ny < Max && A[nx][ny] > 0 ) 
                    ice++;                  //주변 얼음 개수 세기
            }
            
            if( ice < 3) reduce.push_back({i,j});         //2개 이하, 얼음 1 녹음
        }
    }
    
    //실제로 녹이기
    for(int i = 0; i < reduce.size(); i++){
        if(A[reduce[i].first][reduce[i].second] > 0) A[reduce[i].first][reduce[i].second]--;
    }
        
    
    //debug();
    
}

int BFS(int a, int b){
    
    queue<pair<int, int>> Q;
    
    Q.push(make_pair(a, b));
    
    Visit[a][b] = true;
    
    int Cnt = 1;
 
    while (!Q.empty()){
        
        int x = Q.front().first;
        int y = Q.front().second;
        
        Q.pop();
 
        for (int i = 0; i < 4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < Max && ny < Max){
                
                if (A[nx][ny] != 0 && Visit[nx][ny] == false){
                    
                    Visit[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                    Cnt++;
                }
            }
        }
    }
    
    return Cnt;
}

int cntIce(){
    
    //debug();
    
    int total = 0;
    
    for(int i = 0; i < Max; i++){
        for(int j = 0; j < Max; j++) {
            
            total += A[j][i];
            
            if(A[j][i] > 0 && !Visit[j][i]){
                
                int Result = BFS(j, i);
                MaxMess = MaxMess < Result? Result : MaxMess;
            }
        }
    }
    
    return total;
}


int main(){
    
    input();
    
    for(int i = 0; i < Q; i++){
        rotate(L[i]);       //회전 
        reduceIce();        //얼음 녹이기
    }
    
    cout << cntIce() << endl;   //모든 얼음의 질량            
    cout << MaxMess << endl;    //덩어리 계산
    return 0;
}
