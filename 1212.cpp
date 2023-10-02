#include <iostream>
#include <string>
using namespace std;

string num;
int intNum;

int main() { //8진수가 주어졌을 때, 2진수로 변환하는 프로그램

    //입력, 첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.
    cin >> num;
    
    if(num == "0") {cout << 0 << endl; return 0;}
    
    intNum = (int)(num[0] - '0');
    
    if(intNum > 3){
        cout << intNum / 4;
        intNum %= 4;
        cout << intNum /2;
        intNum %= 2;
        cout << intNum;
    }
    else if(intNum > 1){
        cout << intNum /2;
        intNum %= 2;
        cout << intNum;
    }
    else if (intNum > 0){
        cout << intNum;
    }
   

    
    for(int i = 1; i < num.size(); i++){
        
        intNum = (int)(num[i] - '0');
        
        cout << intNum / 4;
        intNum %= 4;
        
        cout << intNum /2;
        intNum %= 2;
        
        cout << intNum;
        
    }
    
    // 출력
    //2진수로 변환하여 출력, 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.
	
	return 0;
}
