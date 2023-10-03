#include <iostream>

using namespace std;

int main(){
    
    //영식이가 운동을 하는 과정은 1분 단위로 나누어져 있다
    // 매 분마다 영식이는 운동과 휴식 중 하나를 선택
    
    // 1. 운동
    //운동을 선택한 경우, 맥박 T만큼 증가, 맥박이 X =>  1분 동안 운동을 한 후 맥박이 X+T
    //영식이는 맥박이 M을 넘는 것을 원하지 않기 때문에, X+T가 M보다 작거나 같을 때만 운동을 할 수 있다
    //휴식을 선택하는 경우 맥박이 R만큼 감소, 1분 동안 휴식을 한 후 맥박은 X-R
    // 맥박은 절대로 m보다 낮아지면 안된다
    //영식이의 초기 맥박은 m이다. 운동을 N분 하려고 한다. 이때 운동을 N분하는데 필요한 시간의 최솟값
    //운동하는 시간은 연속되지 않아도 된다.
    
    //다섯 정수 N, m, M, T, R
    
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;
    
    if(M-m < T){ cout << -1; return 0;} //예외처리 
    
    int pulse = m;
    int totalTime = 0;
    
    while(true){
        
        //운동 가능할 경우 
        if( pulse + T <= M){
            pulse += T;
            N--;
        }
        //쉬어야 할 경우
        else{
            pulse -= R;
            if(pulse < m) pulse = m;
        }
        totalTime++;
        
        if(N ==0) break;
    }
    
    cout << totalTime << endl;
    
    return 0;
}
