#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N, temp;
vector<long long> liq;
long long answer = 3000000001;
long long anslist[4];

void input(){
    cin >> N;           //전체 용액의 수 N이 입력      N :  3 이상 5,000 이하의 정수
    
    for(int i = 0; i < N; i++){
        cin >> temp; liq.push_back(temp);
    }
}

int main(){

    input();
    sort(liq.begin(), liq.end());       //1. 정렬
    
    //방법 1) 맨 앞이 음수 중 가장 작은 수 + 맨 뒤 양수 중 가장 큰 수
    //        두 가지의 합이 0에 수렴할 가장 큰 확률!
    for(int first = 0; first < liq.size() - 2; first++){

        int begin = first + 1, end = liq.size() -1;

        while(begin < end){

            long long total = liq[first] + liq[begin] + liq[end];       //해당 인덱스의 최종 값을 비교

            if( abs(total) < answer ){
                answer = abs(total);
                anslist[0] = liq[first];
                anslist[1] = liq[begin];
                anslist[2] = liq[end];
            }

            if(total < 0) begin++;      //최종 값이 음수 => begin의 값보다 큰 값을 더했을 때 최적값 찾을 수 있는 가능성 있음
            else end--;                 //최종 값이 양수 => end의 값보다 작은 값을 더했을 때 최적값 찾을 수 있는 가능성 있음

        }
    }

    cout << anslist[0] << " " << anslist[1] << " " << anslist[2] << endl;
    
    return 0;
}