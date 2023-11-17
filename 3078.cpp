#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    //https://www.acmicpc.net/problem/3078
    
    //모든 학생은 자신과 반 등수의 차이가 K를 넘으면 친구가 아님
    //좋은 친구는 이름의 길이가 같아야 함
    
    int N, K;
    string name;
    
    cin >> N >> K;
    vector<int> arr;
    
    for(int i = 0; i < N; i++){
        cin >> name; arr.push_back(name.size());
    }
    
    int cnt = 0;
    
    //초기 K 끼리 비교
    for(int i = 0; i < K; i++){
        for(int j = i + 1; j < K + 1; j++){
            
            if(arr[i] == arr[j]) cnt++;
        }
    }
    
    //슬라이딩 윈도우
    for(int i = K + 1; i < N; i++){
        
        for(int j = i - K; j < i; j++){
            if(arr[j] == arr[i]) cnt++;
        }
    }
    
    cout << cnt << endl;

    return 0;
}
