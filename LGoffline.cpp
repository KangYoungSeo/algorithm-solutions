#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    
    //https://www.acmicpc.net/problem/20366 눈사람 리뷰
    
    //https://www.acmicpc.net/problem/9024
    int T;
    cin >> T;
    
    while(T-->0){
        
        int N, K, temp; cin >> N >> K;
        vector<int> num;
    
        for(int i = 0; i < N; i++){
            cin >> temp; num.push_back(temp-K);
        }
        
        //정렬
        sort(num.begin(),num.end());
        
        //이분 탐색 (용액문제와 유사)
        
        int front = 0, end = N - 1;
        
        int min = 1000000000;
        int cnt = 0;
        
        while(front < end){
        
            int sum = num[front] + num[end];
            int abs_sum = abs(sum);
            
            if(sum == 0){
            
                if(min == 0) cnt++;      //이미 최적의 값을 도달했을 경우
                
                else{                   //최적의 값을 처음 도달했을 경우
                    min = 0; cnt = 1;
                }
                
                //앞쪽 or 뒤쪽 확인
                //int sum_front = num[front+1] + num[end];
                //int sum_end = num[front] + num[end-1];
                
                break;                  //탐색 끝
                
            }
            else if(sum < 0){
                
                if(min > abs_sum){      //이전에 찾은 최적값보다 더 가까울 경우,
                    
                    min = abs_sum; cnt = 1;
                    
                }
                else if(min == abs_sum) cnt++; //이전에 찾은 최적값과 같을 경우,
                
                front++;
            }
            else if(sum > 0){
                
                if(min > abs_sum){      //이전에 찾은 최적값보다 더 가까울 경우,
                     min = abs_sum; cnt = 1;
                }
                else if(min == abs_sum) cnt++; //이전에 찾은 최적값과 같을 경우,
                
                end--;
            }
        }
        
        cout << min << endl;
    }
    
    /* 3078 
    
    //https://www.acmicpc.net/problem/3078
    
    //모든 학생은 자신과 반 등수의 차이가 K를 넘으면 친구가 아님
    //좋은 친구는 이름의 길이가 같아야 함
    
    int N, K;
    string name;
    
    cin >> N >> K;
    vector<pair<int,int>> temp;
    
    for(int i = 0; i < N; i++){
        cin >> name;
        temp(make_pair(i,name.size()));
    }
    */
    return 0;
}
