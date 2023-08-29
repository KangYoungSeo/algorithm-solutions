//IQ test
#include <iostream>

using namespace std;

int main(){

    int a, b, N;
    int number[52];
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> number[i];
    
    //1-2, 2-3로 연립일차방정식 풀기

    //숫자가 한개일 경우, 다양한 경우의 수 출연
    if(N == 1){
        cout << "A" << endl; return 0;
    }
    
    //둘이 같을 경우
    if(N == 2){
        
        //숫자가 죄다 동일할 경우 그 다음 숫자도 같은 값 출현
        if(number[0] == number[1]) cout << number[0] << endl;
        
        //아닐 경우, 경우의 수가 너무 많으니까 A 출력
        else cout << "A" << endl;
        
        return 0;
    }
    
    
    //나누는 값
    int Anum = number[0] - number[1];
    
    //나눠지는 값
    int Xnum = number[1] - number[2];
    
    //나누는 값이 0일 경우 = 값이 계속 일정한 경우
    if(Anum == 0){
        a = 1; b = 0;
    }
    // 아닐 경우 a, b 구하기
    else{
        a = Xnum / Anum;
        b = number[1] - a * number[0];
    }
    
    //그 다음 number들이 이 a, b의 규칙에 맞게 되어있는지 확인 하나씩
    for(int i = 1; i < N; i++){
        
        if(number[i] != number[i-1]*a + b){
            cout << "B" << endl;
            return 0;
        }
    }
        
    cout << number[N-1] * a + b << endl;
    

    return 0;
}