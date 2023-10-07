#include <iostream>

using namespace std;

int main(){
    
    //정수 N의 가장 뒤 두 자리를 적절히 바꿔서 N을 F로 나누어 떨어지게 만들려
    //가능한 것이 여러 가지이면, 뒤 두 자리를 가능하면 작게 만들려
    int N, F; cin >> N >> F;
    
    
    //ex1) N=275이고, F=5이면, 답은 00이
    //ex2) N=1021이고, F=11이면, 정답은 01
    
    N -= N % 100;
    
    for(int i = N; ;i++){
        if(i % F == 0){
            if(i % 100 < 10) cout << "0";
            cout << i % 100;
            break;
        }
    }
    
    return 0;
}
