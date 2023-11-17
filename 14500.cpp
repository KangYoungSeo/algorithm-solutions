#include <iostream>

using namespace std;

int N, M, temp;
int map[501][501];

int result;

//삼성 이전 기출

void search(int x, int y){
    
    //테트리스를 놓을 수 있는 방법 search
    int sum;
    
    // 1) 1 X 4
    if(x + 3 < N){
        sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+3][y];
        if(sum > result) result = sum;
    }
    
    // 2) 4 X 1 
    if(y + 3 < M){
        sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x][y+3];
        if(sum > result) result = sum;
    }
    
    // 3 X 2
    // 끝 인덱스 수정하기 
    if(x + 2 < N && y + 1 < M){
        
        //3 ~ 8
        sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x+1][y+2];
        if(sum > result) result = sum;
        
        sum = map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+1][y+2];
        if(sum > result) result = sum;
        
        sum = map[x][y] + map[x+1][y] + map[x][y+1] + map[x][y+2];
        if(sum > result) result = sum;
        
        sum = map[x][y+2] + map[x+1][y] + map[x+1][y+1] + map[x+1][y+2];
        if(sum > result) result = sum;
        
        
        
        sum = map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x+1][y+2];
        if(sum > result) result = sum;
        
        sum = map[x+1][y] + map[x+1][y+1] + map[x][y+1] + map[x][y+2];
        if(sum > result) result = sum;  
        
        sum = map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x][y+2];
        if(sum > result) result = sum;
        
        sum = map[x+1][y] + map[x+1][y+1] + map[x+1][y+2] + map[x][y+1];
        if(sum > result) result = sum;
        
    }
    
    // 2 X 3
    if(x + 1 < N && y + 2 < M){
        
        // 9 ~ 14
        sum = map[x][y+1] + map[x+1][y+1] + map[x+2][y+1] + map[x][y];
        if(sum > result) result = sum;
        
        sum = map[x][y+1] + map[x+1][y+1] + map[x+2][y+1] + map[x+2][y];
        if(sum > result) result = sum;
        
        sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x][y+1];
        if(sum > result) result = sum;
        
        sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+2][y+1];
        if(sum > result) result = sum;
        
        
        
        sum = map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+2][y+1];
        if(sum > result) result = sum;
        
        sum = map[x][y+1] + map[x+1][y+1] + map[x+1][y] + map[x+2][y];
        if(sum > result) result = sum;  
        
        
        sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+1][y+1];
        if(sum > result) result = sum;
        
        sum = map[x][y+1] + map[x+1][y+1] + map[x+2][y+1] + map[x+1][y];
        if(sum > result) result = sum;
        
    }
    
    // 15) 2 X 2
    if(x + 1 < N && y + 1 < M){
        sum = map[x][y] + map[x+1][y] + map[x][y+1] + map[x+1][y+1];
        if(sum > result) result = sum;
    }
}


int main(){
    
    //2초 512MB
    cin >> N >> M;

    //input
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    
    
    // 폴리오미노 => 정사각형 서로 겹치면 X, 도형은 모두 연결되어야함
    
    // 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램
    
    // 크기가 N×M인 종이 위에 테트로미노 하나 놓기
    // 테트로미노가 놓여질 수 있는 방법은 여러가지 => 계산을 통해 최대인지 확인
    
    result = -1;
    // 빡구현 탐색
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            
            cout << i << " " << j << endl;
            
            search(i,j);
        }
    }
    
    cout << result << endl;
    
    return 0;
}
