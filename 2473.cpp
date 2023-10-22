#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, temp;
vector<int> liq;

void input(){
    cin >> N;           //전체 용액의 수 N이 입력      N :  3 이상 5,000 이하의 정수
    
    for(int i = 0; i < N; i++){
        cin >> temp; liq.push_back(temp);
    }
}

int main()
{
    input();
    
    sort(liq.begin(), liq.end());       //1. 정렬
    
    for(int begin = 0, end = liq.size()-1; begin < end;){
        
        
    }
    
    return 0;
}
