#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321

using pli = pair<int,int>;

vector<pli> connect[1001];
vector<int> dist(1001, INF);


//너무 싫은 다익스트라...!!ㅠㅠ
void dijkstra(int start){
    
    dist[start] = 0;        //거리 초기화
    priority_queue<pli> pq; //우선순위 큐
    pq.push({dist[start], start});  //해당 시작점을 먼저 queue에 추가, 거리 + 도시 이름
    
    while(!pq.empty()){     //queue에 탐색해야할 node가 있을 때까지 탐색
    
        int current = pq.top().second;  // 탐색하게 된 node의 도시 이름
        
        int distance = pq.top().first * -1 ;  // 탐색하게 된 node의 현재까지 start에서 current 정점 사이의 거리를 계산
        
        pq.pop();                       // 계산 순위
        
        // 현재 탐색하게 된 node의 거리와 비교
        if( dist[current] < distance ) continue; 
        
        
        for(int i = 0; i < connect[current].size(); i++){
            
            int next = connect[current][i].first;   // current의 정점과 연결된 정점
            
            int nextDistance = connect[current][i].second + distance;
            
            //현재까지의 start에서 current 정점까지의 최소 거리 vs current를 지나 next까지의 거리 추가 current ~ next까지 distance
            
            if( nextDistance < dist[next] ){        // 만약 current를 지나가는 것이 더 가까울 경우
                dist[next] = nextDistance;
                
                pq.push({ nextDistance * -1, next });//새롭게 갱신 weight & vertex
                
            }
            
        }
        
    }
    
}


int main(){
 
   //N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 
   //우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 
   //A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.
    int N, M;
    //첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 
    cin >> N >> M;
    //그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 
    
    //버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.
    
    for(int i = 0; i < M ; i++){
        int start; cin >> start;    //먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 
        int arrive; cin >> arrive;  //그리고 그 다음에는 도착지의 도시 번호가 주어지고
        int cost; cin >> cost;      //버스 비용이 주어진다.
        
        connect[start].push_back({arrive,cost});
    }
    
    //그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 
    //출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.
    int start; cin >> start;
    int arrive; cin >> arrive;
    
    dijkstra(start);
    
    //첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.
    cout << dist[arrive];
    

    return 0;
}
