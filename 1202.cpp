#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
long long total;

pair<int,int> jewel[300001]; 
int bag[300001];
priority_queue<int, vector<int>, less<int>> pq;

void input(){
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> jewel[i].first >> jewel[i].second;
    for(int i = 0; i < K; i++) cin >> bag[i];
    total = 0;
}

int main(){
    
    input();
    
    
    //1. 보석과 가방을 가격 순으로 정렬
    sort(jewel, jewel + N);
    sort(bag, bag + K);
    
    int idx = 0;
    
    //2.  이익이 가장 많은 순으로 정렬 후 체크
    for(int i = 0; i < K; i++){
        
        //보석들 중에 해당 가방에다 넣을 수 있는지 확인 => 가장 가치있는 보석을 in
        while(idx < N && bag[i] >= jewel[idx].first){       //해당 보석이 가방에 넣을 수 있는지 체크
            pq.push(jewel[idx].second);                     //해당 보석의 가치를 넣기
            idx++;
        }
        if(!pq.empty()){
            total += pq.top(); pq.pop();                    //보석들 중 우선순위 큐를 활용해서 가방에 넣기
        }
    }
    
    cout << total << endl;

    return 0;
}

/*

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int total;

priority_queue<pair<int,int>> jewel; 
vector<int> C;
int bag[100000001];

void input(){
    
    int M, V, temp;
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        
        cin >> M >> V;
        jewel.push(make_pair(M,V));
    }
    
    for(int i = 0; i < K; i++) {
        cin >> temp; C.push_back(temp);
    }
}

int main(){
    
    input();
    
    total = 0;
    
    // 보석을 가격 순으로 정렬
    //sort(jewel, jewel + jewel.size());
    sort(C.begin(), C.end());
    
    
    //1. 이익이 가장 많은 순으로 정렬 후 체크
    while(!jewel.empty()){
        
        int weight = jewel.top().first;
        int value = jewel.top().second;
        
        // 현재 가방에 넣을 수 있는 최적의 가방을 찾기
        for(int i = 0; i < C.size(); i++){

            // 현재 탐색하는 가방에 넣을 수 있다면, 소비하기
            if(C[i] - bag[i] > weight){
                bag[i] += weight;
                total += value;
            }
            
            else continue;          //이미 가방이 차있을 경우 넘어감
        }
    }
    
    cout << total << endl;

    return 0;
}

*/