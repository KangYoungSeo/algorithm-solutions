#include <iostream>

using namespace std;

int main(){
    
    //체스판은 8×8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 있음
    //가장 왼쪽 위칸 (0,0)은 하얀색이다. 
    //체스판의 상태가 주어졌을 때, 하얀 칸 위에 말이 몇 개 있는지 출력
    
    char chess[8][8];
    
    int cnt = 0;
    
    //Y가 0,2,4,6,8.... 일 경우 X가 0,2,4,6,8....
    //Y가 1,3,5,7,9.... 일 경우 Y가 1,3,5,7,9....
    //가 하얀칸
    

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> chess[i][j];
            
            //하얀 칸에 말이 있을 경우
            if( (i+j) % 2 == 0 && chess[i][j] == 'F')
                cnt++;
        }
    }
    
    cout << cnt << endl;

    return 0;
}
