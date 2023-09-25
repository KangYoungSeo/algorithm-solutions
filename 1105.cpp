#include <iostream>

using namespace std;

int main()
{
    int L, R; cin >> L >> R;
    
    
    //8의 최소값인 문제.
    //결국 내가 8을 어쩔수 없이 품어야하는 경우는 
    //두 개의 숫자 사이에 공통된 숫자가 될 경우임.
    //특히나
    
    int lowNum[10];
    int highNum[10];
    
    //숫자 쪼개기
    int low = L;
    int Lidx = 0;
    
    while(low != 0){
        //가장 아래 자리수를 배열에 저장
        lowNum[Lidx++] = low % 10;
        low /= 10;
    }
    
    int high = R;
    int Ridx = 0;
    
    while(high != 0){
        //가장 아래 자리수를 배열에 저장
        highNum[Ridx++] = high % 10;
        high /= 10;
    }
    
    //둘이 자리수가 다를 경우, 무조건 0
    if(Lidx != Ridx){
        cout << 0 << endl;
        return 0;
    }
    
    int max = Lidx;
    
    int cnt = 0;
    
    //같은 숫자가 몇 개인지 확인
    for(int i = max - 1; i >=0 ; i--){
        
        //숫자가 같을 경우
        if(lowNum[i] == highNum[i]){
            
            // 그 숫자가 8일 경우
            if(lowNum[i] == 8) cnt++;
        }
        
        //아닐 경우는 볼 필요도 없이 패스
        else break;
    }
    
    cout << cnt << endl;
    
    return 0;
}
