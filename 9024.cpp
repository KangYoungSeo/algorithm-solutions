#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    //https://www.acmicpc.net/problem/9024
    int T;
    cin >> T;
    
    while(T-->0){
        
        int N, K, temp; cin >> N >> K;
        vector<int> num;
    
        for(int i = 0; i < N; i++){
            cin >> temp; num.push_back(temp);
        }
        
        //정렬
        sort(num.begin(),num.end());
        
        //이분 탐색 (용액문제와 유사)
        
        int front = 0, end = N - 1;
        
        int min = 1000000000;
        int cnt = 0;
        
        while(front < end){
        
            int sum = num[front] + num[end];
            int dif = sum - K;
            
            if(sum == K){
            
                front++;
                end--;
            }
            else if(sum < K) front++;
            else if(sum > K) end--;
            
            if(abs(K- sum) < min){
                min = abs(K-sum);
                cnt = 1;
            }
            else if(abs(K-sum) == min) cnt++;
        }
        
        cout << cnt << endl;
    }
   
    return 0;
}