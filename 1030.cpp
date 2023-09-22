#include <iostream>
#include <cmath>

using namespace std;

int S, N, K;
int R1, C1, R2, C2; // (C1,R1) ~ (C2,R2) 계산하기

int MAX;
int outSizeY, outSizeX;

//출력 값
bool board[51][51];

void Recursive(int Nsize, int t, int X, int Y){
    
    cout << Nsize << " " << t << " " << X << " " << Y << endl;
    
    int Ksize = K * pow(N,S - t);
    
    //가운데 계산
    int middleL = (Nsize - Ksize)/2; // 작은
    int middleR = (Nsize + Ksize)/2; // 큰

    cout << Ksize << " " << middleL << " " << middleR << endl;
    
    //가운데에 해당하는 칸이 해당 칸에 해당하는지 확인.
    for(int i = middleL + Y; i < middleR + Y; i++){
        if(R1 > i || R2 < i) continue;
        
        for(int j = middleL + X; j < middleR + X; j++){
            if(C1 > j || C2 < j) continue;
            
            //범위에 해당한다면 색칠하기
            board[i - R1][j - C1] = true;
        }
    }

    
    //세분화 종료 시, return 0
    if(S == t) return;
    
    //인덱스 세분화 후에, 분할 정복하기
    
    //왼쪽 위
    if(R1 <= Y + middleL && C1 <= X + middleL){
        Recursive(Nsize/N, t +1, 0, 0 );
    }
    
    //중간 위
    if(R1 <= Y + middleL && C1 <= X + middleR && C2 >= X + middleL){
        
        cout << "중간 위 탐색" << endl;
        Recursive(Nsize/N, t +1, X + middleL, 0 );
    }
    
    //오른쪽 위
    if(C2 >= Y + middleR && X + middleL >= R1){
        Recursive(Nsize/N, t +1, X + middleR, 0 );
    }
    
    //왼쪽 중간
    if(C1 <= X + middleL && R1 <= Y + middleR && R2 >= Y + middleL){
        cout <<"왼쪽 중간 탐색" <<endl;
        Recursive(Nsize/N, t +1, 0, Y + middleL);
    }
    
    //오른쪽 중간
    if(C2 >= X + middleR && R1 <= Y + middleR && R2 >= Y + middleL){
        Recursive(Nsize/N, t +1, X + middleR, Y + middleL);
    }
    
    //왼쪽 아래
    if(C1 <= X + middleL && R2 >= Y + middleR){
        Recursive(Nsize/N, t +1, 0, Y + middleR);
    }
    
    //중간 아래
    if(R2 >= Y + middleR && C1 <= X + middleR && C2 >= X + middleL){
        Recursive(Nsize/N, t +1, X + middleL, Y + middleR);
    }
    
    //오른쪽 아래
    if(C2 >= X + middleR && R2 >= Y + middleL){
        Recursive(Nsize/N, t +1, X + middleR, Y + middleR);
    }
}

int main(){
    
    //input
    cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
    outSizeY = R2 - R1 + 1;
    outSizeX = C2 - C1 + 1;
    MAX = pow(N,S);
    
    //Recursive
    Recursive(MAX,1,0,0);
    
    //output
    for(int i = 0; i < outSizeY ; i++){
        for(int j = 0; j < outSizeX; j++){
            cout << board[i][j];   
        }
        cout << endl;
    }

    return 0;
}
